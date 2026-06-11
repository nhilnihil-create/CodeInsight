#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 998244353;
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
    string s;
    cin>>s;
    ll n = s.length();
    ll l[n], r[n];
    l[n-1] = n-1;
    r[0] = 0;
    for (int i=1; i<n; i++)if (s[i] == 'R')r[i]=i; else r[i] = r[i-1];
    for (int i=n-2; i>=0; i--)if (s[i]=='L')l[i] = i; else l[i] = l[i+1];
    ll store[n]; memset(store, 0, sizeof(store));
    for (int i=0; i<n; i++){
        if (s[i] == 'L')continue;
        ll x = l[i] - i;
        if (x&1)store[l[i]-1]++;
        else store[l[i]]++;
    }
    for (int i=0; i<n; i++){
        if (s[i]=='R')continue;
        ll x = i - r[i];
        if (x&1)store[r[i]+1]++;
        else store[r[i]]++;
    }
    for (int i=0; i<n; i++)cout<<store[i]<<" ";
}