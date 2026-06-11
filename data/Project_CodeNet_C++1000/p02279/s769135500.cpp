#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

vector<int> g[100001];
int par[100001],dep[100001];
bool nroot[100001];
void dfs(int v,int p,int d){
    par[v]=p,dep[v]=d;
    rep(i,g[v].size()){
        dfs(g[v][i],v,d+1);
    }
}
int main(){
    int n;
    cin>>n;
    int id,k,ci;
    rep(i,n){
        cin>>id>>k;
        rep(i,k){
            cin>>ci;
            g[id].pb(ci);
            nroot[ci]=true;
        }
    }
    int root;
    rep(i,n)if(!nroot[i]) root=i;
    dfs(root,-1,0);
    rep(i,n){
        cout<<"node "<<i<<": parent = "<<par[i]<<", depth = "<<dep[i]<<", ";
        if(root==i) cout<<"root";
        else if(g[i].size()>0) cout<<"internal node";
        else cout<<"leaf";
        cout<<", [";
        rep(j,g[i].size()) cout<<g[i][j]<<(j+1==g[i].size()?"":", ");
        cout<<"]"<<endl;
    }
    return 0;
}
