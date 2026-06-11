#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(v) for (auto itr = v.begin(), itr != v.end(); ++itr)
#define LB(v, x) lower_bound(v.begin(), v.end(), x) - v.begin()
#define UB(v, x) upper_bound(v.begin(), v.end(), x) - v.begin()
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;



int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll S;
    cin >> S;
    int x1 = 0, y1 = 0, x2 = (int)1e9, y2 = 1;
    int x3 = (x2 - S % x2) % x2;
    int y3 = (S + x3) / x2;
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3
         << endl;

    return 0;
}
