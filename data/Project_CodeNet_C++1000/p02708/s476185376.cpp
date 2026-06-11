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

const ll mod = 1e9+7;

int main()
{
    ll n,k;
    cin>>n>>k;
    ll ans=0;
    for(ll i=k;i<=n+1;i++)
    {
        ll mn=((i-1)*(i)/2);
        ll ma=((n+n-i+1)*(i)/2);
        ans=(ans+ma-mn+1)%mod;
    }
    cout<<ans<<endl;
    return 0;
}
