#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

//vector出力
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){
  o<<"{";
  for(int i=0;i<(int)v.size();i++) o << (i>0?", ":"") << v[i];
  o<<"}";
  return o;
}

int seen[2000000];  // 1:現在探索中のパスで行きがけ 2:探索後の頂点
int d[2000000];     // d[i]:= 始点から i への距離
int dfs(const vector<vector<int>> &G, int now) {
    if (seen[now] == 2) return d[now];
    seen[now] = 1;
    for (auto e : G[now]) {
        if (seen[e] == 1) {  // 閉路を検出
            cout << -1 << endl;
            exit(0);
        }
        chmax(d[now], dfs(G, e) + 1);
    }
    seen[now] = 2;
    return d[now];
}

int main() {
  int N,a,b;
  cin >> N;
  vector<vector<int>> g(N*(N-1)/2+1);
  rep(i,N){
    int bno=N*(N-1)/2;
    rep(j,N-1) {
      a = i;
      scanf("%d",&b);
      b--;
      if (a>b) swap(a,b);
      int no = b*(b-1)/2 + a;
      g[bno].push_back(no);
      swap(bno,no);
    }
  }

  cout << dfs(g, N*(N-1)/2) << endl;
}