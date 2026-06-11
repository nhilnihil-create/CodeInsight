#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    rep(i, n) {
        int a;
        cin >> a;
        p[i] = {a, i + 1};
    }
    sort(p.begin(), p.end());
    rep(i, n) {
        if (i != 0)
            cout << " ";
        cout << p[i].second;
    }
    cout << endl;

    return 0;
}