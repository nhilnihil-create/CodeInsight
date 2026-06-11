#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define F first
#define S second
#define mod 1000000007
#define pb push_back
#define ret return 0
#define ios ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const int NUM = 2e5 + 5;
vector<ll> g[NUM];
int n,k;
bool vis[NUM];
ll ans = 0;
void dfs(int node, int par){
    int availchoice = k-1;
    if(par!=-1) --availchoice;
    for(auto u:g[node]){
        if(u==par) continue; // already visited
        if(availchoice<=0){
            ans = 0;
            return ;
            // No colors left to paint the node
        }
        ans = (ans*availchoice)%mod;
        --availchoice;
        dfs(u,node);

    }
}
int main(){
    ios
    int num_tests=1; 
    //cin>>num_tests;
    while(num_tests-->0){
        cin>>n>>k;
        memset(vis,0,sizeof(vis));
        
        for(int i=0;i<n-1;i++){
            int x,y; cin>>x>>y;
            g[x].pb(y);
            g[y].pb(x);
        }
        
        ans = k; // choices to paint the root
        dfs(1,-1);
        cout<<ans;
    }   
}
