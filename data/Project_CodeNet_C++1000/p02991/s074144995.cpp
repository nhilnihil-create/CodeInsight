#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N, M;
  cin>>N>>M;
  vector<vector<int> > edge(N);
  int u, v;
  for(int i=0;i<M;++i) {
    cin>>u>>v;
    u--;
    v--;
    edge[u].push_back(v);
  }
  int S, T;
  cin>>S>>T;
  S--;
  T--;
  queue<pair<int, int> > que;
  que.push(mp(S, 0));
  pair<int, int> state;
  map<pair<int, int>, int> amap;
  for(int i=0;i<N;++i) {
    for(int j=0;j<3;++j) {
      amap[mp(i, j)] = -1;
    }
  }
  while(!que.empty()) {
    state = que.front();que.pop();
    if(amap[mp(state.fi, state.se%3)]>-1) continue;
    amap[mp(state.fi, state.se%3)] = state.se;
    for(int i=0;i<edge[state.fi].size();++i) {
      if(amap[mp(edge[state.fi][i], (state.se+1)%3)]>-1) continue;
      que.push(mp(edge[state.fi][i], (state.se+1)));
    }
  }
  if(amap[mp(T, 0)]==-1) cout<<-1<<endl;
  else cout<<amap[mp(T, 0)]/3<<endl;
}

