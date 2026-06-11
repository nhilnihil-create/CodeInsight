/*
    NO 
        TIME 
            TO 
                DIE
                    --007
                            */
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
//#include <boost/functional/hash.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long int lli;
lli mod=998244353;
#define OS //single input use oeis
lli INF=9223372036854775807;
lli eps=1e-8;
#define IO ios_base::sync_with_stdio(0);
#define sqr(x) (x) * (x)
#define bip(n) __builtin_popcountll(n)//no of ones bit in binary!!
#define bictz(n) __builtin_ctzll(n)//no of trailing zeroes in binary!!
#define biclz(n) __builtin_clzll(n)//no of leading zeroes in binary!!
#define bffs(n) __builtin_ffsll(n)//index of first one bit!!
typedef pair<lli,lli> ll;
#define mem1(a,x) fill(&a[0], &a[0] + sizeof(a) / sizeof(a[0]), x)
#define mem2(a,x) fill(&a[0][0], &a[0][0] +sizeof(a)/sizeof(a[0][0]),x)
#define mem3(a,x) fill(&a[0][0][0], &a[0][0][0] +sizeof(a)/sizeof(a[0][0][0]),x)
#define fi1 ifstream fin("input.txt")
#define of1 ofstream fout("output.txt")
int fmx(int x, int y) { return (((y-x)>>(31))&(x^y))^y; }
int fmi(int x, int y) { return (((y-x)>>(31))&(x^y))^x; }
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ost;
lli n,k,m,d,b,c,q,x;
int vis[100005];
void dfs(int i,vector<vector<int>>& v)
{
    vis[i]=1;
    for(auto &j: v[i])
    {
        if(!vis[j])
            dfs(j,v);
    }
}

int main()
{
 #ifndef ONLINE_JUDGE
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 #endif
 
 int n,m;
 cin>>n>>m;
 vector<vector<int>> v(n+1);
 for(int i=1;i<=m;i++)
 {
    int x,y;
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
 }
 int ans=0;
 for(int i=1;i<=n;i++)
 {
    if(!vis[i])
        dfs(i,v),ans++;
 }

 cout<<ans-1;
 
}

