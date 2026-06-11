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
        int a, b; cin >> a >> b;
        int h, m; cin >> h >> m;
        double w = (h * 60 + m) / 2. - m * 6.;
        if (w < 0) w += 360;
        w = min(w, 360 - w);
        cout << fixed << setprecision(10) << sqrt(a * a + b * b - 2 * a * b * cos(w * M_PI / 180));
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
