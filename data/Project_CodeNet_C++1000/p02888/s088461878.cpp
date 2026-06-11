#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<vector>
using namespace std;
#define ll long long
#define db double
ll len[2005];
vector <ll> L;
int main()
{
    ll n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&len[i]);
        L.push_back(len[i]);
    }
    sort(L.begin(),L.end());
    ll ans=0;
    for(ll i=0;i<n-2;i++)
    {
        for(ll j=i+1;j<n-1;j++)
        {
            auto it=lower_bound(L.begin(),L.end(),L[i]+L[j]);
            ll cnt=distance(it,L.end());
            ans=ans+n-1-j-cnt;
        }
    }
    printf("%lld",ans);
    return 0;
}

