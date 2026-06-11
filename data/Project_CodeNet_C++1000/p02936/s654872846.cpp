#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
//const ll MOD=998244353;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main()
{
  ll N,Q; cin>>N>>Q;
  vector<vector<ll>> graph(N,vector<ll>(0));
  rep(i,N-1){
    ll a,b; cin>>a>>b; a--; b--;
    graph.at(a).push_back(b);
    graph.at(b).push_back(a);
  }
  vector<ll> counter(N,0);
  rep(i,Q){
    ll p,x; cin>>p>>x; p--;
    counter[p]+=x;
  }
  
  //bfs
  vector<int> checked(N,0);
  queue<ll> que;
  que.push(0);
  
  while(!que.empty()){
    ll v=que.front(); que.pop();
    checked.at(v)=1;
    for(auto nv:graph.at(v)){
      if(checked[nv]) continue;
      counter[nv]+=counter[v];
      que.push(nv);
    }
  }
  
  rep(i,N){
    if(i!=0) cout<<" ";
    cout<<counter[i];
  }
  cout<<endl;
  
  return 0;
}