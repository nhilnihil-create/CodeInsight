/*
||-----------------------------------||
||        Rahat Khan Pathan          ||
||      BGC Trust University         ||
||       Department of CSE           ||
||-----------------------------------||
*/
#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define pub push_back
#define pi 3.14159265359
#define pob pop_back
#define puf push_front
#define pof pop_front
#define vi vector<int>
#define vll vector<ll>
#define All(X) (X).begin(),(X).end()
#define Unique(X) (X).erase(unique(All(X)),(X).end()))
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mp make_pair
#define vpair vector<pair<ll,ll>>
#define N 100000
using namespace std;
int parent[N];
int rankParent[N];
void makeSet(ll n)
{
    ll i;
    for(i=1;i<=n;i++)
    {
        parent[i]=i;
        rankParent[i]=0;
    }
}
ll findParent(ll x)
{
    if(x!=parent[x])
    {
        return parent[x]=findParent(parent[x]);
    }
    else
    {
        return x;
    }
}
void makeUnion(ll a,ll b)
{
    ll pa=findParent(a);
    ll pb=findParent(b);
    if(pa==pb)
        return;
    if(rankParent[pa]<rankParent[pb])
    {
        parent[pa]=pb;
    }
    else if(rankParent[pa]>rankParent[pb])
    {
        parent[pb]=pa;
    }
    else
    {
        parent[pb]=pa;
        rankParent[pa]++;
    }
}
struct cell
{
    ll u;
    ll v;
    ll w;
};
vector<cell>v;
bool vis[N];
bool cmp(cell &a,cell &b)
    {
        return a.w<b.w;
    }
ll kruskal(ll n)
{
    makeSet(n);
    sort(v.begin(),v.end(),cmp);
    ll dis=0,i;
    for(i=0;i<v.size();i++)
    {
        if(findParent(v[i].u)!=findParent(v[i].v))
        {
            makeUnion(parent[v[i].u],parent[v[i].v]);
            dis+=v[i].w;
        }
    }
    return dis;
}
int main()
{
    fast;
    ll n,a,b,i,e,c;
    cin>>n>>e;
    for(i=0;i<e;i++)
    {
        cin>>a>>b>>c;
        v.pub({a,b,c});
    }
    ll ans=kruskal(n);
    cout<<ans<<endl;
    return 0;
}


