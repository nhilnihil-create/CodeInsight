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
        int n, k; cin >> n >> k;
        vector<int> h(n); cin >> h;
        vector<bool> good(n, 1);
        while (k--) {
                int a, b; cin >> a >> b;
                a--, b--;
                if (h[a] >= h[b]) good[b] = 0;
                if (h[b] >= h[a]) good[a] = 0;
        }

        cout << accumulate(all(good), 0);
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
