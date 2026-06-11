#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
const int mod = 1e9 + 7, N = 2e6 + 5;
int x, y;
ll fact[N], inv[N];
ll fp(ll base, ll exp){
    if (exp == 0) return 1;
    ll ans = fp(base, exp / 2);
    if (exp % 2 == 0) return (ans * ans) % mod;
    else return (((ans * ans)% mod) * base)% mod;
}
void calcFacAndInv(){
    fact[0] = inv[0] = 1;
    for (ll i = 1; i <= N; i++){
        fact[i] = (i * fact[i - 1]) % mod;
        inv[i] = fp(fact[i], mod - 2);
    }
}
ll ncr(ll n, ll r){
    if(n - r < 0){
        cout << 0;
        exit(0);
    }
    return ((fact[n] * inv[r]) % mod * inv[n - r]) % mod;
}
int main()
{
    Hello
    calcFacAndInv();
    cin >> x >> y;
    if((x + y) % 3 || (2 * x - y) < 0) cout << 0;
    else cout << ncr((x + y)/3, (2 * x - y)/3);
    return 0;
}
