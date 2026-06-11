#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}




void _main() {
        int n, m; cin >> n >> m;
        vector<int> a(n); cin >> a;
        sort(all(a));
        priority_queue<int> pq(all(a));
        while (m--) {
                int x = pq.top(); pq.pop();
                pq.emplace(x / 2);
        }

        ll ans = 0;
        while (pq.size()) {
                ans += pq.top();
                pq.pop();
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