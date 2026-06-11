#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main()
{
  ll N; cin>>N;
  vector<vector<pair<ll,ll>>> graph(N,vector<pair<ll,ll>>(0));
  vector<ll> connect(N-1,-1);
  rep(i,N-1){
    ll a,b; cin>>a>>b; a--; b--;
    graph.at(a).push_back({b,i});
    graph.at(b).push_back({a,i});
  }
  
  //まずは色の数
  ll K=0; rep(i,N) chmax(K,(ll)graph.at(i).size());
  
  //bfs
  queue<ll> que;
  que.push(0);
  while(!que.empty()){
    ll v=que.front(); que.pop();
    ll used_color=-1;
    for(auto p:graph.at(v)){
      ll nv,con; tie(nv,con)=p;
      if(connect.at(con)>-1) used_color=connect.at(con);
    }
    ll color=0; if(color==used_color) color++;
    for(auto p:graph.at(v)){
      ll nv,con; tie(nv,con)=p;
      if(connect.at(con)>-1) continue;
      connect.at(con)=color;
      que.push(nv);
      color++; if(color==used_color) color++;
    }
  }
  
  //解答
  cout<<K<<endl;
  for(auto con:connect) cout<<con+1<<endl;
  return 0;
}