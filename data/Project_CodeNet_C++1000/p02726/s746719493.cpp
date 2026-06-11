//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    ll n,x,y; cin>>n>>x>>y;
    vector<ll>ans(n-1);
    Graph G(n);
    rep(i,n-1){
        G[i].push_back(i+1);
        G[i+1].push_back(i);
    }
    G[x-1].push_back(y-1);
    G[y-1].push_back(x-1);
    rep(i,n){
        vector<ll>dist(n,-1);
        dist[i]=0;
        queue<ll>q;
        q.push(i);
        while(!q.empty()){
            ll b=q.front();
            q.pop();
        for(auto p:G[b]){
            if(dist[p]!=-1)continue;
            dist[p]=dist[b]+1;
            ans[dist[p]-1]++;
            q.push(p);
        }
    }
    }
    rep(i,n-1)cout<<ans[i]/2<<endl;
}

















































