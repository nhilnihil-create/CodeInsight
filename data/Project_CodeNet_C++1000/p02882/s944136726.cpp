#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}





void _main() {
        double a, b, x; cin >> a >> b >> x;
        if (a * a * b < 2 * x){
                double y = 2 * (b - x / (a * a));
                cout << fixed << setprecision(10) << atan(y / a) * 180 / M_PI << '\n';
        }
        else {
                double y = (2 * x) / (a * b);
                cout << fixed << setprecision(10) << atan(b / y) * 180 / M_PI;
        }
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}