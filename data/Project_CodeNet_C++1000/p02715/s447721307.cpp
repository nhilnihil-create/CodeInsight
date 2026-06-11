#include<iostream>
#include<cstdio>
#include <stdio.h>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<map>
#include<vector>
#include <set>
#define ll long long
#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#define inf 0x3f3f3f3f
#define pi 3.1415926535898
using namespace std;
ll f[200010];
const ll mod = 1e9+7;
ll x,y,z;
ll pows(int n,int a)
{
    ll ans=1;
    while(a)
    {
        if(a&1)
        {
            ans=1ll*ans*n%mod;
        }
        n=1ll*n*n%mod;
        a>>=1;
    }
    return ans;
}
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=k;i>=1;i--)
    {
        f[i]=pows(k/i,n);
        for(int j=2*i;j<=k;j+=i)
        {
            f[i]=(f[i]-f[j]+mod)%mod;
        }
    }
    ll ans=0;
    for(int  i=1;i<=k;i++)
    {
        ans+=1ll*i*f[i]%mod;
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}
