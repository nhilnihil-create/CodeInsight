
#include<bits/stdc++.h>
#include<stdio.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;


#define ll                  long long
#define scl(n)              scanf("%lld",&n)
#define scll(n, m)          scanf("%lld%lld",&n, &m)
#define scc(c)	            scanf("%c",&c)
#define fr(i,n)             for (ll i=0;i<n;i++)
#define fr1(i,n)            for(ll i=1;i<=n;i++)
#define pfl(x)              printf("%lld\n",x)
#define pb                  push_back
#define debug               cout<<"I am here"<<endl;
#define pno                 cout<<"NO"<<endl
#define pys                 cout<<"YES"<<endl
#define tcas(i,t)           for(ll i=1;i<=t;i++)
#define all(x) 	            (x).begin(), (x).end()
#define allrev(x)           (x).rbegin(),(x).rend()
#define pr                  pair<ll, ll>
#define ff                  first
#define ss                  second
#define pn                  printf("\n")

#define N 200005

ll m,n,k, a[N],cut=0;

bool is_posi(ll x)
{
    cut=0;
    fr(i, n)
    {
        cut += a[i] / x;
        if (a[i] == x )cut--;
    }

    //return cut<=k;

    if(cut<=k)return 1;
    else return 0;
}

int main()
{
    ll t;
    t=1;
    tcas(cs, t)
    {
        cin>>n>>k;
        ll cnt=0,cn=0,ans,sum=0, mx=-1 ;
        fr(i, n)cin>>a[i];

        ll l=1 , r=1e9, mid;
        ans=mx;

        while(l<=r)
        {
            mid=(l+r)/2;
            if(is_posi(mid ) )r=mid-1  , ans=mid;
            else l=mid+1;
        }

        cout<<ans<<endl;
    }

return 0;
}

/// **************************Before submit****************************

///    ****Please check all base case output  and printing " YES or NO " ***
///    *check for integer overflow,array bounds
///    *check for n=1
