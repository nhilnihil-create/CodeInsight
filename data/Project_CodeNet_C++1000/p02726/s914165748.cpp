#include<bits/stdc++.h>
using namespace std;
#define PI          acos(-1)
#define INF         100000000
#define sc(n)       scanf("%d",&n);
#define ssc(n)      scanf("%s",n);
#define lsc(n)      scanf("%lld",&n);
#define dsc(n)      scanf("%lf",&n);
#define csc(n)       scanf("%c",&n);
#define LL          long long int
#define UI          unsigned int
#define ULL         unsigned long long int
#define DB          double
#define pii         pair<int,int>
#define VI          vector<int>
#define MII         map<int,int>
#define PB          push_back
#define MP          make_pair
#define M(mx,a)     mx=max(mx,a)
#define IT          ::iterator
#define all(a)      a.begin(),a.end()
#define mems(a,b)   memset(a,b,sizeof(a))
#define F(i,a,b)    for(i=a;i<b;i++)
#define IN(n,aa)    for(i=0;i<n;i++)scanf("%d",&aa[i]);
#define PNT(n,aa)   for(i=0;i<n;i++)printf("%lld ",aa[i]);
#define mod         1000000007
#define NUM         10000
#define NUM2        1000000000
int n;
map<int,int>mp;
bool vis[NUM];
int dist[NUM];
vector<int>vv[NUM];
void bfs(int x)
{
    mems(vis,0);
    mems(dist,-1);
    vis[x]=1;
    dist[x]=0;
    queue<int>qq;
    qq.push(x);
    while(!qq.empty())
    {
        x=qq.front();
        qq.pop();
        for(int i=0;i<vv[x].size();i++)
        {
            if(!vis[vv[x][i]])
            {
                qq.push(vv[x][i]);
                vis[vv[x][i]]=1;
                dist[vv[x][i]]=dist[x]+1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        mp[dist[i]]++;
    }
}

int main()
{
    int T=1,QQ=0;
    //cin >> T ;
    while(T--)
    {
        int x,y,i,j;
        cin >> n >> x >> y ;
        for(i=1;i<n;i++)
        {
            vv[i].PB(i+1);
            vv[i+1].PB(i);
        }
        vv[x].PB(y);
        vv[y].PB(x);
        for(i=1;i<=n;i++)bfs(i);
        for(i=1;i<n;i++)cout << mp[i]/2 << endl ;
    }
}

//printf("Case %d: ",++QQ);
