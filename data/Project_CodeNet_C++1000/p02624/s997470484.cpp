#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int INF = 1 << 29;
const int MOD = 1000000007;

// Nを与えると素因数分解をし、{素数:個数}のmapを返す
map<long long, long long> prime_factorize(long long n) {
    map<long long, long long> mp;
    for (long long a = 2; a * a <= n; a++) {
        if (n % a != 0) continue;
        long long exp = 0;  // 指数

        // 割れる限り割り続ける
        while (n % a == 0) {
            exp++;
            n /= a;
        }

        mp[a] = exp;
    }

    // 最後に残った数が1でないのならN自身が素数
    if (n != 1) mp[n] = 1;
    return mp;
}

// prime_factorize を使用してNの約数の個数を返す
long long factor_num(long long n) {
    long long num = 1;
    map<long long, long long> mp = prime_factorize(n);
    for (auto p : mp) num *= p.second + 1;
    return num;
}

int main() {
    long long n;
    cin >> n;

    // 正整数jに対し、jの倍数であってN以下であるものの総和をg(j)としたとき
    // sum_{j = 1}^{N} g(j)が解答となる
    // y = floor(N/x)とおくと g(x) = xy(y+1)/2 であるためO(N)で解ける

    long long sum = 0;

    rep(i, n) {
        long long j = i + 1;
        long long y = n / j;
        sum += j * y * (y + 1) / 2;
    }
    cout << sum << endl;
}