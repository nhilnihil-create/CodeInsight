#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
#include <stdio.h>
#include <bits/stdc++.h>


using namespace std;
#define ll long long
#define ld long double
#define  P pair<ll,ll>
#define FOR(i,n,m) for(ll i=n; i<(ll)m;i++)
#define FORa(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define FORr(i,m,n) for(ll i=n; i>=(ll)m; i--)
#define FORm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define ALL(c) (c).begin(), (c).end()
#define VEC2(x,a,b) vector<vector<ll>> x = vector<vector<ll>>(a,vector<ll>(b,0))
#define sortAl(v) sort(v.begin(),v.end())
#define sortAlr(v) sort(v.begin(),v.end()); reverse(v.begin(),v.end())
#define cinv(v,n,m) FOR(i,n,m) cin>>v.at(i)
#define coutv(v,n,m) FOR(i,n,m) cout<<v.at(i) <<" "; cout<<endl
#define cout(n) cout<<fixed<<setprecision(n)


//    Edges := 重み付き辺の集合
//    WeightedGraph := 重み付きグラフ
//    UnWeightedGraph := 重み無しグラフ
//    Matrix := 距離行列
template< typename T >
struct edge {
  ll src, to;
  T cost;

  edge(ll to, T cost) : src(-1), to(to), cost(cost) {}

  edge(ll src, ll to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator ll() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< ll > >;
template< typename T >
using Matrix = vector< vector< T > >;


//計算量(VE)
ll INF = numeric_limits< ll >::max();
template< typename T >
vector< T > shortest_path_faster_algorithm(WeightedGraph< T > &g, ll s)
{
  const auto INF = numeric_limits< T >::max();
  vector< T > dist(g.size(), INF);
  vector< ll > pending(g.size(), 0), times(g.size(), 0);
  queue< ll > que;

  que.emplace(s);
  pending[s] = true;
  ++times[s];
  dist[s] = 0;

  while(!que.empty()) {
    ll p = que.front();
    que.pop();
    pending[p] = false;
    for(auto &e : g[p]) {
      T next_cost = dist[p] + e.cost;
      if(next_cost >= dist[e.to]) continue;
      dist[e.to] = next_cost;
      if(!pending[e.to]) {
        if(++times[e.to] >= g.size()) return vector< T >();
        pending[e.to] = true;
        que.emplace(e.to);
      }
    }
  }
  return dist;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll v,e,r;
    cin>>v>>e>>r;
    WeightedGraph<ll> g(v);
    FOR(i,0,e){
      ll in1,in2,c;
      cin>>in1>>in2>>c;
      g[in1].push_back(edge<ll>(in1,in2,c));
    }
    vector<ll> res = shortest_path_faster_algorithm(g,r);
    if(res.size() == 0) cout<<"NEGATIVE CYCLE"<<endl;
    FOR(i,0,res.size()){
      if(INF == res[i]) cout<<"INF"<<endl;
      else cout<<res[i]<<endl;
    }
}

