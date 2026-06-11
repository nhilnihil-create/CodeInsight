// 6/26 解き直し
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a%b);
}

int main() {
    ll A, B;
    cin >> A >> B;

    ll d = gcd(A, B);

    // ll prime = 2;
    vector<int> primes;

    primes.push_back(1);

    for (int i = 2; i <= 1e6; i++) {
        if (d % i == 0) {
            primes.push_back(i);
        }
        while (d % i == 0) {
            d /= i;
        }
    }

    if (d != 1) {
        primes.push_back(d);
    }

    cout << primes.size() << endl;
}