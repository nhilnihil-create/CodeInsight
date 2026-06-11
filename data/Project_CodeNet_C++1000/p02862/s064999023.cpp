// https://atcoder.jp/contests/abc145/tasks/abc145_d
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define CEIL(a, b) ((a - 1) / b + 1)

const int MOD = 1e9 + 7;

template <int N, typename T, T M> struct factorial_mod {
    T mod[N + 1];
    T inv_mod[N + 1];

    constexpr factorial_mod() : mod(), inv_mod() {
        mod[0] = 1;
        for (int i = 0; i < N; ++i) {
            mod[i + 1] = (mod[i] * (i + 1)) % M;
        }
        inv_mod[N] = power(mod[N], M - 2);
        for (int i = N - 1; i >= 0; --i) {
            inv_mod[i] = (inv_mod[i + 1] * (i + 1)) % M;
        }
    }

    constexpr T power(T a, T b) {
        T r = 1;
        while (b > 0) {
            if ((b & 1) != 0)
                r = (r * a) % M;
            a = (a * a) % M;
            b >>= 1;
        }
        return r;
    }

    constexpr T comb(T n, T r) {
        return (((mod[n] * inv_mod[r]) % M) * inv_mod[n - r]) % M;
    }
};
factorial_mod<1000001, long long, MOD> facmod;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int X, Y;
    cin >> X >> Y;
    if (X > Y) {
        swap(X, Y);
    }
    // 今後X < Yとする
    if ((X + Y) % 3 != 0) {
        cout << "0\n";
        return 0;
    }
    // 移動回数は(n + m) = (X + Y) / 3;
    // X座標は n + 2m = X;
    // Y座標は 2n + m = Y;
    // 以上から
    // m = X - (X + Y)/3;
    // n = Y - (X + Y)/3;
    int m = X - (X + Y) / 3;
    int n = Y - (X + Y) / 3;
    if (m < 0 || n < 0) {
        cout << "0\n";
        return 0;
    }
    cout << facmod.comb(m + n, m) << endl;

    return 0;
}
