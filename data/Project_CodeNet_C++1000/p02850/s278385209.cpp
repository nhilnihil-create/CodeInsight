#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using ll = long long;
using ld = long double;
using namespace std;
const int INF = 1e9+100;
const ll INF64 = 7e18l;
const int mod = 1000000007;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(), (a).end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using Edge = pair<int,int>; //(隣接頂点、辺番号)
using Graph = vector<vector<Edge>>;
int N;
Graph G;
vector<int> ans;

void dfs(int v,int p,int pc){
    int color = 1;
    if(color == pc) ++color;
    for(auto e : G[v]){
        if(e.first == p) continue;
        ans[e.second] = color;
        dfs(e.first,v,color); //dfsの順番気を付ける
        color++;
        if(color == pc) color++;
    }
}


int main(){
    FIN;

    cin >> N;
    G.assign(N,vector<Edge>());
    for(int i=0;i<N-1;i++){
        int a,b; cin >> a >> b;
        a--; b--;
        G[a].push_back(Edge(b,i));
        G[b].push_back(Edge(a,i));
    }
    int max_color = 0;
    for(int i=0;i<N;i++) max_color = max(max_color,(int)G[i].size());
    ans.assign(N-1,-1);
    dfs(0,-1,-1);
    cout << max_color << endl;
    for(auto res : ans) cout << res << endl;

    return 0;
}