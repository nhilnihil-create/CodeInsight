#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define shalaby ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);cerr.tie(0);

using namespace std;

inline int D()
{
    int t;
    scanf("%d",&t);
    return t;
}
inline ll llD()
{
    ll t;
    scanf("%lld",&t);
    return t;
}
ll mod=1e9+7;
const int OO=-1e6;
int xt[4]= {1,0,0,-1};
int yt[4]= {0,1,-1,0};
////////////////////////////////////////////////////////////////////////////////////
 vector <int> adj[200005];
    bool visited[200005];
const int N = 1e6+1;
ll greatestPF[N];
int cnt,nodes,edges;
  void dfs(int s) {
        visited[s] = true;
        cnt++;

        for(int i = 0;i < adj[s].size();++i)    {
         if(visited[adj[s][i]] == false)
         {
             dfs(adj[s][i]);
         }
        }
    }

int mem[100005][3],a[200005],b[105],n,m,k,frq[1000005];
bool valid(int x,int y)
{
    return x>-1 && y>-1 && x<n && y<m;
}
void init()
{
    memset(mem,-1,sizeof mem);
}
int sieve[N];
int main()
{
int x,y;
     cin >> nodes;
        cin >> edges;
        for(int i = 0;i < edges;++i) {
         cin >> x >> y;
         adj[x].push_back(y);
         adj[y].push_back(x);
        }
        int mx=0,mn=2000006;
        for(int i = 1;i <= nodes;++i) {
         if(visited[i] == false)     {
             dfs(i);
           ///  cout<<i<<" "<<cnt<<endl;
             mx=max(cnt,mx);
             mn=min(cnt,mn);
             cnt=0;
         }
    }
cout<<mx-mn+mn;
}
