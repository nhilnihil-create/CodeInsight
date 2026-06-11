#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
typedef pair<int,int> pp;
bool com(pp x,pp y){
    return x.ff<y.ff;
}
int N=1e5+9,k;
void input_(){
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
}
void dfs(int u,vector<int> &vis,std::vector<std::vector<int>> &vtx){
    vis[u]=1;
    for(auto v:vtx[u]) if(vis[v]==0) dfs(v,vis,vtx);
}
void solve(){
	int n,m;
    cin>>n>>m;
    vector<vector<int>> vtx(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        vtx[u].pb(v);
        vtx[v].pb(u);
    }
    int ans=0;
    std::vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i,vis,vtx);
            ans++;
        }
    }
    cout<<ans-1;
}
int main(){
    input_();
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	int t=1;
	//cin>>t;
	while(t--) 
	    solve();
	return 0; 
}