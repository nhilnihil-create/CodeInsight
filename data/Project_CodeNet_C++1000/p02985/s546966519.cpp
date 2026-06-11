#include <bits/stdc++.h>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


typedef  long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;


#define endl "\n"
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const int N=5e5+5;
int mod=1e9+7;

ll mul (ll a, ll b)
{
    a%=mod;
    b%=mod;
    return (a*b)%mod;
}
ll add (ll a, ll b)
{
    a%=mod;
    b%=mod;
    return (a+b+mod)%mod;
}
ll fastpow(ll b, ll p)
{
    if(p==0)
        return 1;
    ll ans=fastpow(b,p/2);
    ans=mul(ans,ans);
    if(p%2)ans=mul(ans,b);
    return ans;
}

vector<int>v[N];
ll ans=1;
ll n,k;
bool vist[N];

void dfs(int x,ll co)
{
    if (vist[x])
    return ;
    vist[x]=1;
    ans=mul(ans,co);
    ll c=k-2;
    for(int i=0;i<v[x].size();i++)
    {
        if(!vist[v[x][i]])
            dfs(v[x][i],c--);
    }

}


int main()
{
    FIO
    int root=0;
    cin>>n>>k;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int co=0;
    for(int i=1;i<=n;i++)
    {
        if(v[i].size()>co)
            co=v[i].size(),root=i;
    }
    ans=mul(ans,k);
    ll c=k-1;
    vist[root]=1;
    for(int i=0;i<v[root].size();i++)
    {
                if(!vist[v[root][i]])
                    dfs(v[root][i],c--);



    }

    cout<<ans;
    return 0;
}
