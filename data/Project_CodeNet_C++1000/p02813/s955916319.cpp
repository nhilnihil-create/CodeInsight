// https://atcoder.jp/contests/abc150/tasks/abc150_c
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
    vector<int> P(N), Q(N), A(N);
    for (auto &x : P) {
        cin >> x;
    }
    for (auto &x : Q) {
        cin >> x;
    }
    iota(ALL(A), 1);
    int cnt = 0, cntP = 0, cntQ = 0;
    do {
        bool flagP = true, flagQ = true;
        REP(i, N) {
            if (A[i] != P[i]) {
                flagP = false;
            }
            if (A[i] != Q[i]) {
                flagQ = false;
            }
        }
        if (flagP) {
            cntP = cnt;
        }
        if (flagQ) {
            cntQ = cnt;
        }
        cnt++;

    } while (next_permutation(ALL(A)));
    cout << abs(cntP - cntQ) << endl;

    return 0;
}
