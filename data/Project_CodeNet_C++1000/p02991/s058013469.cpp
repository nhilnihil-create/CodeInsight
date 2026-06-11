#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define pll pair<ll,ll>
#define pint pll
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

struct edge{int to,cost;};
int V;
vector<edge> G[500010];
ll d[500010];
 
void dijkstra(int s){
  priority_queue<pint,vector<pint>,greater<pint>> que;
  fill(d,d+V,longinf);
  d[s]=0;
  que.push(pint(0,s));
  
  while(!que.empty()){
    pint p=que.top(); que.pop();
    int v=p.second;
    if(d[v]<p.first)continue;
    rep(i,G[v].size()){
      edge e=G[v][i];
      if(d[e.to]>d[v]+e.cost){
        d[e.to]=d[v]+e.cost;
        que.push(pint(d[e.to],e.to));
      }
    }
  }
}

int main(){
  int E;
  cin >> V >> E;
  rep(i,E){
    int x,y;
    cin >> x >> y;
    x--,y--;
    rep(i,3)G[x+i*V].push_back({y+((i+1)%3)*V,1});
  }
  int s,t;
  cin >> s >> t;
  s--,t--;
  V*=3;
  dijkstra(s);
  if(d[t]==longinf){
    cout << -1 << endl;
    return 0;
  }
  cout << d[t]/3 << endl;
return 0;}