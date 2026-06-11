#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;
const ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (auto &c : a) cin >> c.fi >> c.se;
    for (int i = 0; i <= 999; i++) {
        string lol = to_string(i);
        if ((int)lol.size() != n) continue;
        bool f = true;
        for (auto &c : a) {
            if (lol[c.fi - 1] - '0' != c.se) f = false;
        }
        if (f) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
