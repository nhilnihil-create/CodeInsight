//
// Created by aarav on 9/11/2020.
//

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const string nl = "\n";

bool prime(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

vector<bool> sieve(int n) {
    vector<bool> prime(n + 1, true);

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    return prime;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N;
    cin >> N;
    if (N == 1) {
        cout << 0 << nl;
        exit(0);
    }
    vector<bool> isprime = sieve(1000001);
    long long ans = 0;
    vector<ll> primes;
    ll mx = (ll) sqrt(N);
    for (long long i = 2; i <= mx; i++) {
        if (isprime[i] && ((N % i) == 0)) {
            long long cnt = 0;
            while (N % i == 0) {
                cnt++;
                N /= i;
            }
            long long c = 1;
            while (((c + 2) * (c + 1) / 2) <= cnt)
                c++;
            ans += c;
        }
    }
    if (N > 1)
        ans++;
    if (ans == 0)
        cout << 1 << nl;
    else
        cout << ans << nl;

}
