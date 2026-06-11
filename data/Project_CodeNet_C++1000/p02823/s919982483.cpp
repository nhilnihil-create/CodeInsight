// https://atcoder.jp/contests/agc041/tasks/agc041_a
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
    int N, A, B;
    cin >> N >> A >> B;
    if ((B - A) % 2 == 0) {
        cout << (B - A) / 2 << endl;
    } else {
        cout << min(A - 1, N - B) + 1 + (B - A) / 2 << endl;
    }

    return 0;
}
