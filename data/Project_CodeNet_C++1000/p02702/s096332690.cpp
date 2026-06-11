#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 2019;
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
    int n = 2019;
    long long int a[n];
    memset(a, 0, sizeof(a));
    ll rem = 0;
    a[0] = 1;
    ll l = s.length();
    for (int i=l-1; i>=0; i--){
        rem = (rem + mul(ll((s[i]-'0')), power(10, l-i-1)))%mod;
        // cout<<"rem is "<<rem<<endl;
        a[rem]++;
    }
    long long int ans = 0;
    for (int i=0; i<n; i++)if (a[i]>1)ans += (a[i]*(a[i]-1))/2;
    cout<<ans<<endl;
}