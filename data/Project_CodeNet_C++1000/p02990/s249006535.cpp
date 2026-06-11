#pragma GCC optimize("O3")

#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define pii pair<int,int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define IO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define read(FILE)  freopen(FILE, "r", stdin);
#define out(FILE) freopen(FILE, "w", stdout);
#define all(x) x.begin(),x.end()
#define rep(i, m, n) for(int i=m ; i<n ; i++)
#define forr(i, m, n) for(ll i=m ; i<=n ; i++)
#define clr(v, val) memset(v,val,sizeof(v))
#define endl '\n'
#define pb push_back
#define pff push_front
#define re return
const int N = 3e4 + 5;
const ll mod = ll(1e9) + 7;
using namespace std;
ll fact[N], inv[N];

ll fp(ll base, ll exp) {
    if (exp == 0)
        re 1;
    ll ans = fp(base, exp / 2);
    ans = (ans * ans) % mod;
    if (exp % 2 != 0)
        ans = (ans * (base % mod)) % mod;
    re ans;
}

void calcFacAndInv(ll n) {
    fact[0] = inv[0] = 1;
    for (ll i = 1; i <= n; i++) {
        fact[i] = (i * fact[i - 1]) % mod;
        inv[i] = fp(fact[i], mod - 2);
    }
}

ll ncr(ll n, ll r) {
    re ((fact[n] * inv[r]) % mod * inv[n - r]) % mod;
}

int main() {
    IO;
    calcFacAndInv(N);
    ll n, k;
    cin >> n >> k;
    forr(i, 1, k) {
        ll ans = 0;
        if (n - k + 1 >= i) {
            ans = (ncr(n - k + 1, i) % mod) * (ncr(k - 1, i - 1) % mod);
            ans %= mod;
        }
        cout << ans << endl;
    }

}