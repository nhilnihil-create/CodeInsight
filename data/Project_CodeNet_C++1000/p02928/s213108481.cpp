#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
ll mul(ll a, ll b){
    return ((a%mod) * (b%mod))%mod;
}
ll power(ll a, ll b){
    ll z = 1; ll x = a;
    while(b>0){
        if (b&1)z = mul(z, x);
        x = mul(x, x);
        b >>= 1;
    }
    return z;
}
int main()
{
    ll n, k;
    cin>>n>>k;
    ll ans  = 0;
    ll a[n]; for (int i=0; i<n; i++)cin>>a[i];
    ll k1[n] = {0}, k2[n]={0};
    for (int i=0; i<n; i++){
        for (int j=i-1; j>=0; j--)if (a[i]>a[j])k2[i]++;
        for (int j=i+1; j<n; j++)if (a[i] > a[j])k1[i]++;
    }
    for (int i=0; i<n; i++){
        ans += (mul(k1[i], k*(k+1)/2) + mul(k2[i], k*(k-1)/2))%mod;
    }
    // ans %= mod;
    // ll x = k*(k+1)/2; x %= mod;
    // ans = mul(ans, x);
    ans %= mod;
    cout<<ans<<endl;
}