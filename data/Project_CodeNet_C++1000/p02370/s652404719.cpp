#include<cstring>
#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<cmath>
#include<sstream>
#include<cassert>
#include<string>
#include<algorithm>
#define rep(i,n) for(int i = 0;i<n;i++)
#define Rep(i,n) for(int i = 1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define mult(a,b) (((a)*(b))%MOD)
#define se second
#define INF 1300000
#define MOD 1000000007
using namespace std;
typedef long long int ll;

vector<int> G[100000];
int V,E;
vector<int> order;
bool visited[100000];

void dfs(int now){
    visited[now]=1;
    rep(i,G[now].size()){
        if(!visited[G[now][i]]){
            dfs(G[now][i]);
        }
    }
    order.pb(now);
    return;
}

int main(){
    cin>>V>>E;
    rep(i,E){
        int a,b;
        cin>>a>>b;
        G[a].pb(b);
    }
    rep(i,V){
        if(!visited[i])
            dfs(i);
    }
    reverse(order.begin(),order.end());
    rep(i,V){
        cout<<order[i]<<endl;
    }
}