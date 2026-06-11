#include <bits/stdc++.h>
using namespace std;

bool IsPrime(long long num) {
    if (num < 2)
        return false;
    else if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false;  // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (long long i = 3; i <= sqrtNum; i += 2) {
        if (num % i == 0) {
            // 素数ではない
            return false;
        }
    }
    // 素数
    return true;
}

long long decompositPrime(long long n) {
    long long cnt = 0;
    map<long long, long long> m;

    for (long long p = 2; p * p <= n; p++) {
        if (n % p != 0) continue;
        int num = 0;

        while (n % p == 0) {
            num++;
            n /= p;
        }
        m[p] = num;
    }

    if (n != 1) m[n] = 1;
    
    for (auto itr : m) {
        long long index = 1;
        while (itr.second >= index) {
            cnt++;
            itr.second -= index;
            index ++;
        }
    }

    return cnt;
}

int main() {
    //
    long long num;
    int cnt = 0;

    cin >> num;

    if (IsPrime(num) == true) {
        cout << 1;
        return 0;
    }

    cnt = decompositPrime(num);

    cout << cnt;
    //
}
