#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}




void _main() {
        int n, k, q; cin >> n >> k >> q;
        vector<int> point(n);
        for (int i = 0; i < n; i++) {
                point[i] = k - q;
        }

        while (q--) {
                int a; cin >> a;
                point[a - 1]++;
        }

        for (int i = 0; i < n; i++) cout << (point[i] > 0 ? "Yes" : "No") << '\n';
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}