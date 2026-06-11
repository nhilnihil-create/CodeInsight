#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

// 繰り返し二乗法
// a^n mod pを高速に求める
long long modPow(long long a, long long n, long long p) {
    if (n == 0)
        return 1;
    if (n == 1)
        return a % p;
    if (n % 2 == 1)
        // 奇数のとき
        return (a * modPow(a, n - 1, p)) % p;
    // 偶数のとき
    long long t = modPow(a, n / 2, p);
    return (t * t) % p;
}

int main() {
    long long l, r;
    cin >> l >> r;

    // R - L >= 2019 だと (mod 2019) 取ると必ず0
    // その場合、2019^2調べる間に必ず0になりその時点で打ち切ればよい

    long long mod_min = 2020;

    for (long long i = l; i <= r; i++) {
        for (long long j = i + 1; j <= r; j++) {
            long long num = i * j;
            num = modPow(num, 1, 2019);
            // 0になったら出力して終了
            if (num == 0) {
                cout << 0 << endl;
                return 0;
            }
            // 0でなくmod_minより小さかったらmod_minを更新
            if (num < mod_min) mod_min = num;
        }
    }
    cout << mod_min << endl;
}
