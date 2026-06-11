#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <math.h>
#include <complex>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <functional>
#include <assert.h>
using ll=long long;
#define int ll
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define SZ(x) x.size()
#define fi first
#define se second
const int INF = 1e15;
using namespace std;

template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class T>
inline bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T>
inline bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

struct SCC{
  vector< vector<int> > G,R,T,C;
  vector<int> vs,used,blg,dps;
  SCC(){}
  SCC(int n):G(n),R(n),used(n),blg(n),dps(n){}

  void add_edge(int u,int v){
    G[u].emplace_back(v);
    R[v].emplace_back(u);
  }

  void dfs(int v){
    used[v]=1;
    for(int u:G[v])
      if(!used[u]) dfs(u);
    vs.emplace_back(v);
  }

  void rdfs(int v,int k){
    used[v]=1;
    blg[v]=k;
    C[k].emplace_back(v);
    for(int u:R[v]){
      if(!used[u]) rdfs(u,k);
      chmax(dps[v],dps[u]+1);
    }
  }

  int build(){
    int n=G.size();
    for(int v=0;v<n;v++)
      if(!used[v]) dfs(v);

    fill(used.begin(),used.end(),0);
    int k=0;
    for(int i=n-1;i>=0;i--){
      if(!used[vs[i]]){
        T.emplace_back();
        C.emplace_back();
        rdfs(vs[i],k++);
      }
    }

    for(int v=0;v<n;v++)
      for(int u:G[v])
        if(blg[v]!=blg[u])
          T[blg[v]].push_back(blg[u]);

    for(int i=0;i<k;i++){
      sort(T[i].begin(),T[i].end());
      T[i].erase(unique(T[i].begin(),T[i].end()),T[i].end());
    }
    return k;
  }

  int operator[](int k) const{return blg[k];}
};

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout<<fixed<<setprecision(20);

    int N; cin >> N;
    SCC scc((N+1)*(N+1));
    rep(i,N){
        vi a(N-1);
        for(auto &t:a) cin >> t;
        rep(j,N-1) a[j]=min(i+1,a[j])*N+max(i+1,a[j]);
        rep(j,N-2){
            scc.add_edge(a[j],a[j+1]);
        }
    }
    if(scc.build()!=(N+1)*(N+1)) {
        cout << -1 << endl;
        return 0;
    }
    int ans=0;
    rep(i,(N+1)*(N+1)){
        chmax(ans,scc.dps[i]);
    }
    cout << ans+1 << endl;
}