#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[1000000+5];
ll arr[1000000+5];
/*arr[0]=1;
dp[0]=1;*/
int main()
{
    /*ll n,x=1,i;
    cin>>n;
    ll mod=1000000007;
    ll dp[n+2]
    for(i=1;i<=n-1;i++)
    {
        x=x*2;
        x=x%mod;
    }
    x=x+n-1;
    x=x%mod;
    cout<<x;*/
    /*ll n;
    cin>>n;
    ll a[n],i;
    for(i=0;i<n;i++)
    {
        cin>>n;
    }*/
    ll n,i;
    cin>>n;
    ll mod=1000000007;
    if(n<2)
        cout<<"0";
    else
    {
        arr[0]=1;
        dp[0]=1;
        ll x=1;
        ll y=1;
        ll z=1;
        for(i=1;i<=n;i++)
        {
            x=x*10;
            y=y*9;
            z=z*8;
            x%=mod;
            y%=mod;
            z%=mod;  
        }

        ll ans=(x-2*y+z+mod+mod)%mod;
        cout<<ans;
        

    }
}
