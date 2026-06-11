#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define ZERO_IQ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define debug(x, y) cerr << (#x) << " " << (#y) <<" is " << (x) <<" "<< (y) << endl
#define debug2(x, y, z) cerr << (#x) << " " <<(#y) << " " << (#z) << " is " << (x) << " " << (y) << " " << (z) << endl
#define watch(x) cerr << (#x) << " is " << (x) << endl
const ll mod = 1e9 + 7;
vector<ll> fact(2004), inv(2004);

ll fp(ll base, ll exp) {
    if (exp == 0)
        return 1;
    ll ans = fp(base, exp / 2);
    ans = (ans * ans) % mod;
    if (exp % 2 != 0)
        ans = (ans * (base % mod)) % mod;
    return ans;
}

void calcFacAndInv(ll n) {
    fact[0] = inv[0] = 1;
    for (ll i = 1; i <= n; i++) {
        fact[i] = (i * fact[i - 1]) % mod;
        inv[i] = fp(fact[i], mod - 2);
    }
}

ll ncr(ll n, ll r) {
    if(n<r)return 0;
    return ((fact[n] * inv[r]) % mod * inv[n - r]) % mod;
}

int main() {
    ll n, k;
    cin >> n >> k;
    calcFacAndInv(2003);
    for (int i = 1; i <= k; ++i) {
        cout << 1LL*((ncr(n - k + 1, i) * ncr(k - 1, i - 1)) % mod) << endl;
    }
    return 0;
}