#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define sll(x) scanf("%lld",&x)
#define prll(x) printf("%lld ",x)
#define pri(x) printf("%d ",x)
#define si(x) scanf("%d",&x)
#define el cout << "\n"
#define pb push_back
#define f first
#define s second
#define arrondi(a) (long long)floor(a+0.5);
#define NIL -1
ll N=500005;
ll MAX=9223372036854775807;
ll MOD=1000000007;
long double PI =4*atan(1);
bool visited[1000005];
vector<ll> mp[1000005];
map<ll,ll> pp;
vector<ll> ans;
ll sum;
void dfs(ll s,ll sum)
{
    visited[s]=true;
    ans[s]=sum;
    for (int i=0;i<mp[s].size();i++)
    {
        if (visited[mp[s][i]]==false)
        {
            dfs(mp[s][i],sum+pp[mp[s][i]]);
        }
    }
}
int main()
{
	IOS;
    cout.precision(30);
    ll n,m,a,b,q; cin >> n >> q ; m=n-1;  memset(visited,false,sizeof visited);
    ans.resize(n+1,0);
    for (int i=0;i<m;i++)
    {
        cin >> a >> b;
        mp[a].push_back(b); mp[b].push_back(a);
    }
    for (int i=0;i<q;i++)
    {
        cin >> a >> b;
        pp[a]+=b;
    }
    dfs(1,pp[1]);
    for (int i=1;i<=n;i++) cout << ans[i]<< " " ;
    return 0;
}

