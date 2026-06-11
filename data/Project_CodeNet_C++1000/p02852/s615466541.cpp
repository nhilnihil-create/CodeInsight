#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vec res;

    int pos = n;

    while (pos > 0) {
        bool update = false;
        for (int mv = m; mv > 0; mv--) {
            if (pos - mv < 0) continue;
            if (s[pos-mv] == '1') continue;

            res.push_back(mv);
            pos -= mv;
            update = true;
            break;
        }

        if (!update) {
            cout << "-1" << endl;
            exit(0);
        }
    }

    reverse(all(res));
    int v = res.size();
    rep(i, v) {
        if (i != 0) cout << " ";
        cout << res[i];
    }
    cout << endl;
    return 0;
}