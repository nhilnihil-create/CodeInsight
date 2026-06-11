#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<n; i++)
#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> m(n);
    rep(i, n) {
        int a;
        cin >> a;
        rep(j, a) {
            int x, y;
            cin >> x >> y;
            m[i].push_back(make_pair(x, y));
        }
    }

    int mh = 0;
    rep(bit, (1<<n)) {
        vector<int> N(n);
        rep(i, n) {
            if ((1<<i) & bit) {
                N[i] = 1;
            }
        }

        bool flag = true;
        rep(i, n) {
            if (N[i] == 1) {
                rep(j, m[i].size()) {
                    if (m[i][j].second != N[m[i][j].first-1]) {
                        flag = false;
                    }
                }
            }
        }
        if (flag) {
            int count = 0;
            rep(i, n) {
                if (N[i]) count++;
            }
            mh = max(mh, count);
        }
    }
    cout << mh << endl;
}