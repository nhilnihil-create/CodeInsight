#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}


double ev(int i) {
        return (double)(i * (1 + i) / 2) / i;
}


void _main() {
        int n, k; cin >> n >> k;
        vector<double> pre(n + 1);
        double ans = 0;
        for (int i = 1; i <= n; i++) {
                int x; cin >> x;
                pre[i] = pre[i - 1] + ev(x);
        }

        for (int i = k; i <= n; i++) {
                ans = max(ans, pre[i] - pre[i - k]);
        }
        cout << fixed << setprecision(10) << ans;
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}