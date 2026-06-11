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
        vector<vector<int>> when((int)1e5 + 1);
        m++;

        int from = 1;
        while (n--) {
                int time, cost; cin >> time >> cost;
                if (m - time >= 1) when[m - time].emplace_back(cost);
        }

        ll ans = 0;
        priority_queue<int> pq;

        for (int time = m; time >= 1; time--) {
                while (when[time].size()) {
                        pq.emplace(when[time].back());
                        when[time].pop_back();
                }
                if (pq.size()) ans += pq.top(), pq.pop();
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