#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}


void _main() {
        int n, k; cin >> n >> k;
        vector<int> p(n), c(n); cin >> p >> c;
        auto go = [&](int i) -> ll {
                ll cnt = 0;
                vector<ll> cycle;
                vector<bool> vis(n);
                for (int rep = 0; rep < k; rep++) {
                        i = p[i - 1];
                        if (vis[i - 1]) break;
                        vis[i - 1] = 1;
                        cnt += c[i - 1];
                        cycle.emplace_back(cnt);
                }

                ll res = -1e18;

                for (int j = 1; j <= sz(cycle); j++) {
                        if (k - j < 0) break;
                        int cn = (k - j) / sz(cycle);
                        res = max(res, cycle[j - 1] + max(0LL, cn * cycle.back()));
                }

                return res;
        };


        ll ans = -1e18;
        for (int i = 0; i < n; i++) {
                ans = max(ans, go(i + 1));
        }

        cout << ans;
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
