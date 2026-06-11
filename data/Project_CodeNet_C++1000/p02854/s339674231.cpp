// https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_b
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
    int sum = 0;
    for (auto &x : A) {
        cin >> x;
        sum += x;
    }
    int half = sum / 2;
    int idx = 0, sum1 = 0, sum2 = 0;
    REP(i, N) {
        sum1 += A[i];
        if (sum1 >= half) {
            idx = i;
            break;
        }
    }
    sum2 = sum - sum1;
    int sum3 = sum1 - A[idx];
    int sum4 = sum - sum3;
    cout << min(abs(sum2 - sum1), abs(sum4 - sum3)) << endl;

    return 0;
}
