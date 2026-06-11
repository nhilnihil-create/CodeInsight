// https://atcoder.jp/contests/abc145/tasks/abc145_c
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define CEIL(a, b) ((a - 1) / b + 1)

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    REP(i, N) { cin >> A[i].first >> A[i].second; }
    double sum = 0;
    REP(i, N) {
        FOR(j, i + 1, N) {
            sum += hypot(A[i].first - A[j].first, A[i].second - A[j].second);
        }
    }
    cout << setprecision(10) << 2.0 * sum / N << endl;

    return 0;
}
