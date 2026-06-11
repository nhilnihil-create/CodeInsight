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
        int n; cin >> n;
        vector<vector<pair<int,int>>> t(n);
        for (int i = 0; i < n; i++) {
                int x; cin >> x;
                while (x--) {
                        int a, b; cin >> a >> b;
                        a--;
                        t[i].emplace_back(a, b);
                }
        }


        int ans = 0;
        for (int mask = 0; mask < (1 << n); mask++) {
                bool ok = 1;
                for (int bit = 0; bit < n; bit++) {
                        if (1 << bit & mask) {
                                for (int i = 0; i < sz(t[bit]); i++) {
                                        if (!!(1 << t[bit][i].first & mask) != t[bit][i].second) ok  =0;
                                }
                        }
                }

                if (ok) ans = max(ans, __builtin_popcount(mask));
        }


        cout << ans << '\n';
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
