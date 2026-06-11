#include <bits/stdc++.h>
using namespace std;

map<long long, long long> m;

bool IsPrime(long long num) {
    if (num < 2)
        return true;
    else if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false;  // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            // 素数ではない
            return false;
        }
    }
    // 素数
    return true;
}

long long nCr(const long long n, long long r) {
    if (n == 0) { return 0; }
    if (r == 0) { return 1; }
    if (r == 1) { return n; }
    if (n == r) { return 1; }

    if (r > n / 2) { r = n / 2; }

    long long result = 1;
    for (long long i = 1; i <= r; i++) { result *= (n - i + 1) / i; }

    return (result);
}

void decompositPrime(long long n) {
    // 割る数の初期値
    long long a = 2;
    while (n >= a * a) {
        if (n % a == 0) {
            m[a]++;
            n /= a;
        } else {
            a++;
        }
    }
    // 最後に残った n は素因数
    m[n]++;
}

int main() {
    //
    long long a, b;
    long long cnt = 0;
    cin >> a >> b;

    decompositPrime(a);
    decompositPrime(b);

    m[1]++;
    for (auto itr : m) {
        if (a % itr.first == 0 && b % itr.first == 0) {
            if (IsPrime(itr.first) == true) cnt++;
        }
    }

    cout << cnt;

    //
}