#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using P =pair<int,int>;

const ll mod=1000000007;

int ret=0;
vector<int> vi;

int bfs(const Graph& g,int i){
    vi[i]=1;
    for(auto next:g[i]){
        if(vi[next]!=0)continue;
        ret=bfs(g,next)+1;
    }
    return ret;
} 

int main(){
    int n,m;
    cin>>n>>m;
    Graph G(n);
    vi.assign(n,0);
    set<P> s;
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        P p(a,b);
        P q(b,a);
        if(!s.count(p)&&!s.count(q)){
            G[a].push_back(b);
            G[b].push_back(a);
            s.insert(p);
            s.insert(q);
        }
    }
    int ans=bfs(G,0);
    ret=0;
    rep(i,n){
        if(vi[i]!=0)continue;
        ans=max(ans,bfs(G,i));
        ret=0;
    }
    cout<<ans+1<<endl;

}