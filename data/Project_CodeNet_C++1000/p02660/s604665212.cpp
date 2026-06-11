#include <map>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;
using ll = long long;

ll isPrime(ll n) {
    if (n < 2) return 0;
    for (ll val = 2; val <= sqrt(n); ++val) {
        if (n % val == 0) return val;
    }
    return n;
}


int main() {
    ll n;
    cin >> n;
    map<ll, ll> mp;
    while (n > 1) {
        ll val = isPrime(n);
        mp[val]++;
        n /= val;
    }
    int cnt = 0;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cnt += (-1 + (ll)sqrt(1 + 8 * it->second)) / 2;
    }
    cout << cnt << '\n';
}