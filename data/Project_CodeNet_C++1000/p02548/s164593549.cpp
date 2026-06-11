#include<bits/stdc++.h>
using namespace std;
#define hackcyborg shresth_walia
#define ll long long
#define ld double
#define pb push_back
#define mod 1000000007
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
#define ordered_set tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
ll bp(ll a,ll b,ll m=mod)
{
    ll res=1;
    if(b<0)
        return bp(bp(a,m-2),-b);
    while(b>0)
    {
        if(b&1)
        res=(a*res)%m;
        a=(a*a)%m;
        b/=2;
    }
    return res;
}
const int N = 10000000;
int lp[N+1];
vector<int> pr;
main()
{
    IO
    for (int i=2; i<=N; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back (i);
    }
    for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
        lp[i * pr[j]] = pr[j];
    }
    ll n;
    cin>>n;
    ll ans=0;
    for(int x=1;x<n;x++)
    {
         ll e=1;
         ll w=n-x;
         while(w>1)
         {
             ll r=0;
             ll t=lp[w];
             while(w%t==0)
             {
                 w/=t;
                 ++r;
             }
            e*=(r+1);
         }
         ans+=e;
    }
    cout<<ans;
}
