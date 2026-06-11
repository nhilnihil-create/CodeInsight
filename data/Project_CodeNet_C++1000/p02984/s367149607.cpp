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
        vector<ll> a(n); cin >> a;
        vector<ll> b(n);
        for (int i = 0; i < n; i++) {
                if (i % 2 == 0) b[0] += 2 * a[i];
                else b[0] -= 2 * a[i];
        }
        b[0] /= 2;
        for (int i = 1; i < n; i++) b[i] = 2*  a[i - 1] - b[i - 1];
        cout << b;
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
