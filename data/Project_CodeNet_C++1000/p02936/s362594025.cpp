#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1, 1, -1,-1,1};
int dy[] = {1, 0, -1, 0, 1, 1,-1,-1};
#define INF 1000000000000
#define MAX 200001
#define MOD 1000000007
ll fac[MAX], finv[MAX], inv[MAX];
const int MX = 1000005;

void dfs(int s,Graph &G,vector<int> &ans,vector<int> &visited){
    visited[s]=1;
    for(auto v:G[s]){
        if(visited[v]) continue;
        ans[v]+=ans[s];
        dfs(v,G,ans,visited);
    }
}

int main(){
    int n,q;cin>>n>>q;
    vector<vector<int>> G(n);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> visited(n,0);
    vector<int> ans(n,0);
    for(int i=0;i<q;i++){
        int p,x;cin>>p>>x;
        p--;
        ans[p]+=x;
    }
    dfs(0,G,ans,visited);
    for(int i=0;i<n;i++) cout<<ans[i]<<' ';
    cout<<endl;
}

