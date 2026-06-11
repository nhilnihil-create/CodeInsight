// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <bits/stdc++.h>  
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pl pair<ll,ll>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vl vector<ll>
#define N 100005
#define mod 1000000007
ll prime[1000001];

int main()
{
    ll n;cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    cin>>a[i];
    for(ll i=1;i<=1000000;i++)
    {
        prime[i]=i;
    }
    for(ll i=2;i<=1000000;i++)
    {
        for(ll j=i;j<=1000000;j+=i)
        {
            prime[j]=min(prime[j],i);
        }
    }
    ll p=0;map<ll,ll>m;
    for(ll i=n-1;i>=0;i--)
    {
        if(a[i]!=1)
        {
            ll x=a[i];
            while(x!=1)
            {
                if(m[prime[x]]>0)
                {
                    p=1;
                }
                x/=prime[x];
            }
            x=a[i];
            while(x>1)
            {
                m[prime[x]]=1;
                x/=prime[x];
            }
        }
    }
    if(!p)
    cout<<"pairwise coprime"<<"\n";
    else
    {
        ll g=0;
        for(ll i=0;i<n;i++)
        {
            g=__gcd(g,a[i]);
        }
        if(g==1)
        cout<<"setwise coprime"<<"\n";
        else
        cout<<"not coprime"<<"\n";
    }
    return 0;
}