// https://atcoder.jp/contests/abc134/tasks/abc134_c
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N) { cin >> A[i]; }
    auto cp = A;
    sort(ALLR(cp));
    // 最大値が2つ以上存在するなら、常に最大値を出力
    if (cp[0] == cp[1]) {
        REP(i, N) { cout << cp[0] << "\n"; }
    } else {
        REP(i, N) { cout << (A[i] == cp[0] ? cp[1] : cp[0]) << "\n"; }
    }

    return 0;
}
