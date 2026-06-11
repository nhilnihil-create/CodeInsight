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
        int l, r; cin >> l >> r;
        vector<int> vis(2019);
        int sum = 0;
        for (int i = l; i <= r; i++) {
                sum += !vis[i % 2019];
                vis[i % 2019] = 1;
                if (sum == 2019) break;
        }

        int ans = 1e9;
        for (int i = 0; i < sz(vis); i++) {
                for (int j = 0; j < i; j++) {
                        if (vis[i] && vis[j]) ans = min(ans, (i * j) % 2019);
                }
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
