#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;
const int INF = 1e16;
using Graph = vector<vector<int>>;

signed main(){
  int N, M;
  cin >> N >> M;

  Graph G(N);
  for( int i = 0; i < M; i++ ){
    int U, V;
    cin >> U >> V;
    U--; V--;
    G.at(U).push_back(V);
  }

  int S, T;
  cin >> S >> T;
  S--; T--;

  vector<vector<int>> dist(N, vector<int>(3, -1));
  queue<pair<int, int>> que;
  dist.at(S).at(0) = 0;
  que.push({S, 0});

  while( !que.empty() ){
    pair<int, int> P = que.front();
    int v = P.first;
    int time = P.second;
    que.pop();

    for( auto nv : G.at(v) ){
      int nt = (P.second+1)%3;
      if( dist.at(nv).at(nt) != -1 ) continue; //すでに通っていたらスルー
      dist.at(nv).at(nt) = dist.at(v).at(time)+1;
      que.push({nv, nt});
    }
  }

  if( dist.at(T).at(0) == -1 ) cout << -1 << endl;
  else cout << dist.at(T).at(0)/3 << endl;

 }
