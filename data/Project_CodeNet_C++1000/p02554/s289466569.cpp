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

// 余りが負なら正にして返す
long long modPositive(long long v, long long p) {
    long long res = v % p;
    if (res < 0)
        res += p;
    return res;
}

int main() {
    long long n;
    cin >> n;

    // 全通り →10^n 通り
    // 0がない → 9^n 通り
    // 9がない → 9^n 通り
    // 0と9がない → 8^n 通り
    // 0または9がある → 10^n - 9^n - 9^n + 8^n

    long long ans = modPow(10, n, MOD) - 2 * modPow(9, n, MOD) + modPow(8, n, MOD);
    ans = modPositive(ans, MOD);
    ans = modPow(ans, 1, MOD);

    cout << ans << endl;
}
