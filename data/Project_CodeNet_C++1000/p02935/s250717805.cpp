#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}




void _main() {
        int n; cin >> n;
        vector<double> a(n); cin >> a;
        sort(all(a), greater<>());
        while (a.size() > 1) {
                double x = a.back(); a.pop_back();
                double y = a.back(); a.pop_back();
                a.emplace_back((x + y) / 2);
        }

        cout << a.back();
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}