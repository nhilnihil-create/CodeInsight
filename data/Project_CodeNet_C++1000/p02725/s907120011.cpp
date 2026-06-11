#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;
//#define int ll

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; cout << '\n'; return O;}


void _main() {
        int k, n; cin >> k >> n;
        vector<int> a(n); cin >> a;
        sort(all(a));
        a.insert(a.end(), all(a));
        for (int i = n; i < a.size(); i++) {
                a[i] += k;
        }

        int ans = 1e9;
        for (int i = 0; i + n - 1 < a.size(); i++) {
                ans = min(ans, a[i + n - 1] - a[i]);
        }

        cout << ans;
}

#undef int
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}