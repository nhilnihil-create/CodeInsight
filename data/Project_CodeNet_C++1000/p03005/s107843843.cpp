// https://atcoder.jp/contests/diverta2019-2/tasks/diverta2019_2_a
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int c, int d) { return c / gcd(c, d) * d; }

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << 0 << endl;
    } else {
        cout << max(n - k, 0LL) << endl;
    }

    return 0;
}