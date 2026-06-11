#include<bits/stdc++.h>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define rrep(i,a) for(int i=(int)a-1;i>=0;--i)
#define REP(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RREP(i,a,b) for(int i=(int)a-1;i>=b;--i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<long long> vl;
typedef std::vector<std::vector<long long>> vvl;
#define out(x) cout<<x<<"\n";
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


ll gcd(ll n, ll m) {
    ll tmp;
    while (m!=0) {
        tmp = n % m;
        n = m;
        m = tmp;
    }
    return n;
}
 
ll lcm(ll n, ll m) {
    return abs(n) / gcd(n, m)*abs(m);//gl=xy
}

using namespace std;

int n, m;

template<typename T>
struct edge{
  int to;
  T cost;
  edge(int to,T cost):to(to),cost(cost){}
};


template<typename T>
vector<vector<T>> dijkstra(vector<vector<edge<T>>> &g,int s){//sは始点
  const auto INFTY=numeric_limits<T>::max();//2回以上使うときはオーバーフローに気をつける(INFTYのときはif文で弾くなど)
  vector<vector<int>> dist(n, vector<int>(3, INFTY));
  using p = pair<int, int>;
  using P = pair<T,p>;
  priority_queue<P, vector<P>, greater<P>> pq;
  dist[s][0]=0;
  pq.emplace(dist[s][0],p{s,0});
  while(!pq.empty()){
    auto x=pq.top();pq.pop();
    int v=x.second.first;//頂点
    int u = x.second.second;//頂点の状態
    if (dist[v][u] < x.first)
      continue; //最短距離でなければ飛ばす
    for(auto e:g[v]){
      if(dist[e.to][(u+1)%3]>dist[v][u]+e.cost){
        dist[e.to][(u+1)%3]=dist[v][u]+e.cost;
        pq.emplace(dist[e.to][(u+1)%3],p{e.to,(u+1)%3});
      }
    }
  }
  return dist;
}




void solve()
{
  cin >> n >> m;
  vector < vector<edge<int>>> g(n);
  rep(i,m){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].eb(v, 1);
  }
  int s, t;
  cin >> s >> t;
  s--;
  t--;
  auto d = dijkstra(g, s);
  const auto inf = numeric_limits<int>::max();
  if (d[t][0] ==inf){
    cout << -1 << endl;
  }
  else {
    cout << d[t][0]/3 << endl;
  }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(15);
    solve();
    return 0;
}
