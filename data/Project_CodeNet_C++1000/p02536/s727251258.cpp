#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

long long N,M;
vector<vector<long long> > adj;
vector<bool> vis;

void dfs(int s){
    vis[s]=true;

    for(auto v:adj[s]){
        if(!vis[v]){
            dfs(v);
        }
    }
}
int main()
{
    fast_cin;
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif


    cin>>N>>M;
    adj.resize(N+1);
    vis.resize(N+1,false);
    ll u,v;
    for(ll i=0;i<M;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans=0;
    for(int i=1;i<=N;i++){
        if(!vis[i]){
            dfs(i);
            ans++;
        }
    }
    cout<<ans-1<<"\n";


}
