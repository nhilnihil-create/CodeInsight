// https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_d
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) FORR(i, 0, n)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define FORR(i, s, n) for (int i = (n - 1); i >= s; --i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

signed main() {
    int M;
    cin >> M;
    vector<int> v(10);
    while (M--) {
        int d, c;
        cin >> d >> c;
        v[d] += c;
    }
    int sum = 0;
    REP(i, 10) { sum += v[i] * i; }
    cout << accumulate(ALL(v), 0LL) - 1 + (sum - 1) / 9 << endl;

    return 0;
}
