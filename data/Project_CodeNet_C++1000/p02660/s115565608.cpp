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

int main() {
    long long n;
    cin >> n;
    map<long long, long long> prime;

    // nを素因数分解する
    prime = prime_factorize(n);

    long long count = 0;

    // 各素因数に対して
    for (auto itr : prime) {
        // 指数を1, 2, 3, と減らしていってどこまで引けるか
        long long k = 1;
        while (true) {
            itr.second -= k;
            if (itr.second >= 0) {
                // 指数部分が0以上なら操作できたことになる
                count++;
                k++;
            } else {
                // 指数部分が0より小さい
                break;
            }
        }
    }
    cout << count << endl;
}
