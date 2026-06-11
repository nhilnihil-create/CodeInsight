// https://atcoder.jp/contests/abc149/tasks/abc149_c
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, s, n) for (int i = (s), i##_len = (n); i < i##_len; ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define ALLR(obj) (obj).rbegin(), (obj).rend()
#define DIV(a, b) ((a - 1) / b + 1)

const int SZ = 1e5 + 10;

// constexprな素数列挙(エラトステネスの篩)
// https://259-momone.hatenablog.com/entry/2018/05/06/015026
template <int N> struct Prime {
    bool b[N + 1]; // trueなら素数
    constexpr Prime() : b() {
        fill_n(b, N + 1, true);
        b[0] = b[1] = false;
        for (int_fast64_t i = 2; i <= N; ++i) {
            if (b[i]) {
                for (int_fast64_t j = i * i; j <= N; j += i) {
                    b[j] = false;
                }
            }
        }
    }
};
Prime<SZ> prime;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int X;
    cin >> X;
    while (true) {
        if (prime.b[X]) {
            cout << X << endl;
            break;
        }
        X++;
    }
    return 0;
}
