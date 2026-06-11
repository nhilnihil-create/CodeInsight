#include <iostream>
#include <vector>
using namespace std;

vector<pair<long long, long long> > prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}

long long GCD(long long x, long long y) {
    return y ? GCD(y, x%y) : x;
}

int main() {
    long long A, B;
    cin >> A >> B;
    long long G = GCD(A, B);
    auto pf = prime_factorize(G);
    cout << pf.size() + 1 << endl;
}