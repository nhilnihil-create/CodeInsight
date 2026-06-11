#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef array<int, 3> tri;
typedef array<int, 2> duo;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}



void _main() {
        int n, m, x; cin >> n >> m >> x;
        int cost[n], algo[n][m];
        for (int i = 0; i < n; i++) {
                cin >> cost[i];
                for (int j = 0; j < m; j++) {
                        cin >> algo[i][j];
                }
        }

        int ans = 1e9;
        for (int mask = 0; mask < (1 << n); mask++) {
                int price = 0;
                vector<int> A(m);
                for (int bit = 0; bit < n; bit++) {
                        if (1 << bit & mask) {
                                for (int i = 0; i < m; i++) A[i] += algo[bit][i];
                                price += cost[bit];
                        }
                }
                if (*min_element(all(A)) >= x) ans = min(ans, price);
        }

        cout << (ans == 1e9 ? -1 : ans);
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
