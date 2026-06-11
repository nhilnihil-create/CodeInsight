// https://atcoder.jp/contests/abc145/tasks/abc145_d
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

const int MOD = 1e9 + 7;
const int SZ = 1e6;

template <int N, int M> struct Fact {
    int mod[N + 1];
    int inv_mod[N + 1];
    constexpr Fact() : mod(), inv_mod() {
        mod[0] = 1;
        for (int i = 0; i < N; ++i) {
            mod[i + 1] = (mod[i] * (i + 1)) % M;
        }
        inv_mod[N] = power(mod[N], M - 2);
        for (int i = N - 1; i >= 0; --i) {
            inv_mod[i] = (inv_mod[i + 1] * (i + 1)) % M;
        }
    }

    // aのb乗
    constexpr int power(int a, int b) {
        int r = 1;
        while (b > 0) {
            if ((b & 1) != 0)
                r = (r * a) % M;
            a = (a * a) % M;
            b >>= 1;
        }
        return r;
    }

    // 組み合わせ n C r
    constexpr int comb(int n, int r) {
        return (((mod[n] * inv_mod[r]) % M) * inv_mod[n - r]) % M;
    }

    // 重複組み合わせ n H r
    constexpr int homo(int n, int r) { return comb(n + r - 1, n - 1); }
};
Fact<SZ, MOD> facmod;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int X, Y;
    cin >> X >> Y;
    int x = X, y = Y;
    if ((x + y) % 3 != 0) {
        cout << "0\n";
        return 0;
    }
    int n = (x + y) / 3;
    x -= n;
    y -= n;
    if (x < 0 || y < 0) {
        cout << "0\n";
        return 0;
    }
    cout << facmod.comb(n, x) << endl;
    return 0;
}
