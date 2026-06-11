#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007;

vector<vector<P>> to;
vector<int> color;

void dfs(int v,int pa=-1,int c=0){
    int n=1;
    for(P p : to[v]){
        if(p.first==pa){continue;}
        if(n==c)n++;
        color.at(p.second)=n;
        n++;
        dfs(p.first,v,color.at(p.second));
    }
    return;
}

int main() {
    int N;
    cin>>N;
    to.resize(N,vector<P>(0));
    color.resize(N-1);
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        --a;--b;
        to[a].pb({b,i});
        to[b].pb({a,i});
    }
    int num=0;
    rep(i,N){
        chmax(num,sz(to[i]));
    }
    cout<<num<<endl;
    dfs(0);
    rep(i,N-1){
        cout<<color.at(i)<<endl;
    }
}