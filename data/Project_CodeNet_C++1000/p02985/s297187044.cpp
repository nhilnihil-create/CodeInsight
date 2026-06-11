#include<bits/stdc++.h>
#define prArr(Arr,n) for(int _=0;_<n;_++)   cout<<(Arr)[_]<<" ";
#define f first
#define s second
using namespace std;
const int INF=(int)0x3f3f3f3f;
const int MOD=(int)1e9+7;
const double eps=1e-9;
vector<vector<int>> adj;
void dfs(int,int,int);
long long k,ans=1;
int done[100005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,a,b;
    cin>>n>>k;
    adj.resize(n+1);
    for(int i=0;i<n-1&&cin>>a>>b;i++)
        adj[a].push_back(b),
        adj[b].push_back(a);
    dfs(1,0,0);
    cout<<ans;
    return 0;
}

void dfs(int u,int last,int depth)
{
    ans*=k-min(depth,2)-done[last];
    ans%=MOD;
    for(auto v:adj[u])
    {
        if(v==last)
            continue;
        dfs(v,u,depth+1);
        done[u]++;
    }
    return;
}
