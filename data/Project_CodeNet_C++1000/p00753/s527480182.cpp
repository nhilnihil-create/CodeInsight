//https://onlinejudge.u-aizu.ac.jp/challenges/sources/ICPC/Prelim/1172?year=2011

#include <bits/stdc++.h>

using namespace std;


vector<long long> primes(long long lo, long long hi) { // primes in [lo, hi)
    const long long M = 1 << 14, SQR = 1 << 16;
    vector<bool> composite(M), small_composite(SQR);

    vector<pair<long long, long long>> sieve;
    for (long long i = 3; i < SQR; i += 2) {
        if (!small_composite[i]) {
            long long k = i * i + 2 * i * max(0.0, ceil((lo - i * i) / (2.0 * i)));
            sieve.push_back({2 * i, k});
            for (long long j = i * i; j < SQR; j += 2 * i)
                small_composite[j] = 1;
        }
    }
    vector<long long> ps;
    if (lo <= 2) {
        ps.push_back(2);
        lo = 3;
    }
    for (long long k = lo | 1, low = lo; low < hi; low += M) {
        long long high = min(low + M, hi);
        fill(composite.begin(), composite.end(), 0);
        for (auto &z: sieve)
            for (; z.second < high; z.second += z.first)
                composite[z.second - low] = 1;
        for (; k < high; k += 2)
            if (!composite[k - low]) ps.push_back(k);
    }
    return ps;
}

vector<long long> primes(long long n) { // primes in [0,n)
    return primes(0, n);
}


int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) return 0;

        auto vt = primes(n + 1, 2 * n);
        cout << vt.size() << endl;
    }
}

/*
 * エラトステネスのふるい。
 * 
 */
