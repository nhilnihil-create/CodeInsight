#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll M = 1e9 + 7;
const int iinf = 1 << 29;
const long long llinf = 1ll << 60;
const double PI = 3.14159265;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll mrand(ll B) {
  return (ull)rng() % B;
}

void work() {
    ll n; cin>>n;
    vector<bool> sieve(2e6, true);
    vector<ll> primes;
    for (int i = 2; i < sieve.size(); ++i) {
        if (sieve[i]) {
            primes.push_back(i);
            for (int j = i * i; j < sieve.size(); j += i)
                sieve[j] = false;
        }
    }
    vector<ll> cnt;
    ll orig_n = n;
    for (auto p : primes) {
        if (p * p > orig_n) break;
        if (n % p != 0) continue;
        cnt.push_back(0);
        while (n % p == 0) {
            ++cnt.back();
            n /= p;
        }
    }
    if (n != 1) cnt.push_back(1);
    
    ll ans = 0;
    for (auto e : cnt) {
        for (ll i = 1; i <= e; ++i) {
            e -= i;
            ++ans;
        }
    }
    if (ans == 0 && orig_n > 1LL)
        cout << "1\n";
    else
        cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int nt; cin>>nt; while (nt--) work();
    work();
    return 0;
}
