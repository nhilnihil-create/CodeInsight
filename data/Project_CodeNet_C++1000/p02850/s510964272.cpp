#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

vector<pair<int,int>> G[101010];

int main(){
    int n;
    cin>>n;
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].push_back({b,i});
        G[b].push_back({a,i});
    }

    int ans=0;
    rep(i,n) ans=max(ans,(int)G[i].size());
    cout<<ans<<endl;

    queue<pair<int,int>> q;
    vector<bool> seen(n,false);
    q.push({0,-1});
    seen[0]=true;
    vector<int> res(n-1,-1);
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        int v=p.first,c=p.second;
        int color=1;
        if(color==c) color++;
        for(auto e : G[v]){
            if(seen[e.first]) continue;
            seen[e.first]=true;
            q.push({e.first,color});
            res[e.second]=color;
            color++;
            if(color==c) color++;
        }
    }

    rep(i,n-1) cout<<res[i]<<endl;
}

