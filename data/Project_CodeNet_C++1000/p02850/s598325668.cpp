#include<iostream>
#include<string>
#include<cstring>
#include <cstdio>
#include<utility>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<bitset>
#include<queue>
#include<stack>
#include<set>
#include <limits>
#include <climits>
#include <numeric>
#include <cassert>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<int>VI;
typedef pair<int,int>P;
typedef pair<double,double>P_D;
//const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
#define PI 3.1415926535897932384626433832795
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define reprev(i, n) for (ll i = (ll)n - 1; i >= 0; i--)
#define ALL(a)  (a).begin(),(a).end()
#define C_MAX(a, b) ((a)>(b)?(a):(b))
#define fi first
#define se second
#define MAX 100100//5
#define MAX_N 200100
#define MAX_B 1001001//6
#define MAX_S 10010010//7
#define SENTINEL 2000000000//9
#define NIL -1
#define MOD 1000000007
#define INF 1 << 29
#define INFTY 1000000000000000000LL
#define MAX_INT INT_MAX

using Edge=pair<int,int>;
using Graph =vector<vector<Edge>>;
int n;
Graph G;

void dfs(int v,int p,int pc,vector<int>& res){
    int color=1;
    if(color==pc)++color;
    for(auto e:G[v]){
        if(e.first==p)continue; //逆流しない
        res[e.second]=color;
        dfs(e.first,v,color,res);
        ++color;
        if(color==pc)++color;
    }
}

int main(){
    cin>>n;
    G.assign(n,vector<Edge>());
    for(int i=0;i<n-1;++i){
        int a,b;cin>>a>>b;--a;--b;
        G[a].emplace_back(b,i);
        G[b].emplace_back(a,i);
    }
    int max_color=0;
    for(int i=0;i<n;++i)max_color=max(max_color,(int)G[i].size());
    vector<int>res(n-1,-1);
    dfs(0,-1,-1,res);
    cout<<max_color<<endl;
    for(auto v:res)cout<<v<<endl;
}