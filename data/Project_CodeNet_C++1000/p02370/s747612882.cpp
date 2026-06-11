#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) (v).begin(),(v).end()
#define int long long
#define INF 1e18
#define MOD 1000000007
#define SIZE 100005

using namespace std;
typedef pair<int,int> P;

//-----------------------------------------------------------------------

int V,E;
vector<int> G[10005];
bool used[10005];
vector<int> ans;

void dfs(int v){
    used[v]=true;
    for(auto u:G[v]){
        if(!used[u]) dfs(u);
    }
    ans.push_back(v);
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin>>V>>E;
    REP(i,E){
        int a,b; cin>>a>>b;
        G[a].push_back(b);
    }
    REP(i,V){
        if(!used[i]) dfs(i);
    }
    reverse(ALL(ans));
    REP(i,V) cout<<ans[i]<<endl;
    
 
}

