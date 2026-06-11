#include <bits/stdc++.h>

#define ll long long int

using namespace std;

#define M 1000000007

ll
mpow(ll x, ll n)
{
    ll ans = 1;
    while (n > 0){
        if (n & 1) ans = ans*x % M;
        x = x*x % M;
        n = n >> 1;
    }
    return ans;
}


int main() {
    string L;
    cin >> L;

    ll n = L.size();

    vector<vector<ll>> dp(n, vector<ll>(2));

    ll res = 0;

    ll countBit = 0;
    for (ll i = 0; i < n; ++i) {
        if (L[i] == '1') {
            res += mpow(2, countBit) * mpow(3, n-1-i);
            res %= M;
            ++countBit;
        }
    }
    res += mpow(2,countBit);
    res %= M;
    cout << res << endl;
}
