#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<long long int, long long int> prime_factor(long long int n) {
    map<long long int, long long int> ret;
    for (long long int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if (n != 1) ret[n] = 1;
    return ret;
}

int main() {
    ll A, B;
    cin >> A >> B;

    map<ll, ll> prime_A = prime_factor(A);
    map<ll, ll> prime_B = prime_factor(B);

    int output = 1;
    for (auto var : prime_A) {
        if (prime_B[var.first] != 0) {
            output++;
        }
    }

    cout << output << endl;

    return 0;
}
