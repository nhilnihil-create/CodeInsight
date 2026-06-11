#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const int mod = 1e9 + 7, N = 20000;
ll fact[N], inv[N];
ll fp(ll base, ll exp){
    if (exp == 0) return 1;
    ll ans = fp(base, exp / 2);
    if (exp % 2 == 0) return (ans * ans) % mod;
    else return (((ans * ans)% mod) * base)% mod;
}
void calcFacAndInv(ll n){
    fact[0] = inv[0] = 1;
    for (ll i = 1; i <= n; i++){
        fact[i] = (i * fact[i - 1]) % mod;
        inv[i] = fp(fact[i], mod - 2);
    }
}
ll ncr(ll n, ll r){
    if(r > n) return 0;
    return ((fact[n] * inv[r]) % mod * inv[n - r]) % mod;
}
 
int main(){
    Hello
    calcFacAndInv(N - 5);
    ll n, k;
    cin >> n >> k;
    for(int i = 1; i <= k; i++){
        ll ans = ((ncr(n - k + 1, i) % mod) * (ncr(k - 1, i - 1) % mod))% mod;
        cout << ans << endl;
    }
    return 0;
}