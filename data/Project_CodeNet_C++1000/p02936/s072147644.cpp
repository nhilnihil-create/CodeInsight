#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int64_t i=0; i<(n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()
#define chmax(x,y) x=max(x,y)




int main(){
    int n,q; cin>>n>>q;
    vector<vector<int>> p(n);
    rep(i,n-1){
        int a,b; cin>>a>>b;
        a--; b--;
        p[a].push_back(b);
        p[b].push_back(a);
    }
    vector<ll> padd(n,0);
    rep(i,q){
        int a,b; cin>>a>>b;
        padd[a-1]+=b;
    }
    deque<int> che;
    che.push_back(0);
    vector<ll> ans(n,-1);
    ans[0]=0;
    while(!che.empty()){
        int now=che[0];
        che.pop_front();
        ans[now]+=padd[now];
        for(auto &v: p[now]){
            if(ans[v]!=-1) continue;
            ans[v]=ans[now];
            che.push_back(v);
        }
    }
    rep(i,n){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
