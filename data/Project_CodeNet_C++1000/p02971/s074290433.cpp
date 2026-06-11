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
    // 最大の数と、最大の数が何回出現するか
    int N, maxv = 0, cnt = 0, before = 0;
    cin >> N;
    vector<int> A(N);
    REP(i, N) {
        cin >> A[i];
        if (A[i] > maxv) {
            before = maxv;
            maxv = A[i];
            cnt = 1;
        } else if (A[i] == maxv) {
            cnt++;
        } else {
            before = max(before, A[i]);
        }
    }
    REP(i, N) {
        if (A[i] == maxv && cnt == 1) {
            cout << before << "\n";
        } else {
            cout << maxv << "\n";
        }
    }

    return 0;
}
