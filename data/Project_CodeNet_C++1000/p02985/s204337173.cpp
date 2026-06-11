#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define ll long long
#define rep(i,n) for(int i=0;i<n;++i) 
using namespace std;
static const long long MOD=1000000007;
static const int MAX = 2010;

vector<bool> seen;
ll dfs(vector<vector<int>> &g,int p,int v,int k, int  K){
    seen[v]=true;
    ll ret=k;
    int b= K-1 -((p!=-1)?1:0);
        for(auto a: g[v]){
            if(seen[a])
            continue;
            ret*=dfs(g,v,a,max(0,b),K);
            ret%=MOD;
            b--;
            
        }
        
        return ret;
    
    
 
}

int main(void){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> g(n);
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    seen.assign(n, false);
   cout<<dfs(g,-1,0,k,k);
    
}
