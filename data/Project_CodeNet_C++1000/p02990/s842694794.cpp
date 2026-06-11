#include <bits/stdc++.h>
using namespace std;

#define Omar45 ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mem(x,y) memset((x), (y), sizeof (x));
#define point complex <double>
#define ll long long
#define ld long double
#define pb push_back
#define F first
#define S second
#define endl '\n'
#define PI acos(-1)
const ll mod = 1e9 + 7;
const ll maxN = 1e5 + 5;
const ll INF = 1e18;

ll fact[maxN], inv[maxN];

ll modPow (ll a, ll b){
    if(b == 0)
        return 1;
    ll ret = modPow(a, b / 2);
    ret = ((ret % mod) * (ret %mod))%mod;
    if(b % 2)
        ret = (ret * (a % mod))%mod;
    return ret;
}


void calcFacAndInv(int n){
    fact[0] = inv[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
        inv[i] = modPow(fact[i], mod - 2);
    }
}

ll ncr(ll n, ll r)
{
	return ((fact[n] * inv[r]) % mod * inv[n-r]) % mod;
}

int main() {
	Omar45
	calcFacAndInv(maxN);
    ll n, k; cin >> n >> k;
    for (int i=1; i<=k; i++) {
        if (i > n-k+1) {
            cout << "0" << endl;
            continue;
        }
        ll ans = ncr(n-k+1, i);
        ans *= ncr(k-1, i-1);
        ans %= mod;

        cout << ans << endl;
    }
}