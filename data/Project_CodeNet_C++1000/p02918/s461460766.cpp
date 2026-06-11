// https://atcoder.jp/contests/abc140/tasks/abc140_d
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
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    // L, Rの境界
    int sum = 0;
    REP(i, N - 1) {
        if (S[i] == S[i + 1]) {
            sum++;
        }
    }
    cout << min(N - 1, 2 * K + sum) << endl;

    return 0;
}
