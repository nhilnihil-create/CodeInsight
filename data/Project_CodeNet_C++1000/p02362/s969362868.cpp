#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
vector<int> x4 = {0, 1, 0, -1};
vector<int> y4 = {1, 0, -1, 0};
vector<int> x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
  T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }


template<class T> struct edge { int from, to; T cost;};

int N,M; // 各々頂点数、辺数
const int MAX_N = 1000;
const int MAX_M = 2000;
const int INFC = 1000000000;
vector<int> d(MAX_N);   // 最短距離
vector<edge<int>> es(MAX_M); // 辺              // llにするときはここもllにしてくれ

// s番目の頂点から各頂点への最短距離を求める。但しtrueならアカン負の閉路が存在する
bool bellman_ford(int s){
  rep(i, N) d[i] = INFC;
  d[s] = 0;
  rep(vv, N-1){
    bool update = false;
    rep(i, M){
      auto e = es[i];
      if (d[e.from] != INFC && d[e.to] > d[e.from] + e.cost){
        d[e.to] = d[e.from] + e.cost;
        update = true;
      }
    }
    if (!update) break;
  }
  rep(i, M){   // 離島、負の閉路について
    auto e = es[i];
    if (d[e.from] == INFC) continue;
    if (d[e.from] + e.cost < d[e.to]) return true;
  }
  return false;
}


int main() {
  cin >>N >>M;
  int s; cin >>s;
  rep(i, M){
    int a,b,d; cin >>a >>b >>d;
    es[i] = {a,b,d};
  }
  if (bellman_ford(s)) cout <<"NEGATIVE CYCLE" <<endl;
  else{
    rep(i, N){
      if (d[i] == INFC) cout <<"INF" <<endl;
      else cout <<d[i] <<endl;
    }
  }
}

