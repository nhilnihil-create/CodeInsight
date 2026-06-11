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

vector<vector<int>> to;

int main() {
    int N,M;
    cin>>N>>M;
    to.resize(3*N,vector<int>(0));
    
    rep(i,M){
        int a,b;
        cin>>a>>b;
        --a;--b;
        to[3*a].pb(3*b+1);
        to[3*a+1].pb(3*b+2);
        to[3*a+2].pb(3*b);
    }
    int S,T;
    cin>>S>>T;
    --S;--T;
    S*=3;T*=3;
    
    vector<int> minlen(3*N,-3);
    queue<P> visited;
    visited.push({S,0});
    while(!visited.empty()){
        P v=visited.front();visited.pop();
        if(minlen.at(v.first) == -3){
            minlen.at(v.first)=v.second;
            P nex;
            nex.second=v.second+1;
            for(int u:to[v.first]){
                nex.first=u;
                visited.push(nex);
            }
        }
    }
    cout<<minlen.at(T)/3<<endl;
/*rep(i,N){
    rep(j,to2.at(i).size()){
        cout<<to2.at(i).at(j)<<" ";
    }
    cout<<endl;
}*/
}