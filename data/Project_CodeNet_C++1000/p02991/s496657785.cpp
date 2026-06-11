#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
#include<functional>
#include<stack>
#include<tuple>
#include<cassert>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using ll = long long;
using P = pair<int, int>;
using MATRIX = vector< vector<ll> >;

int N, M;
vector<int> v[100000];
int S, T;
int dist[100000][3];
const int INF = 1000000000;

int main() {
  cin >> N >> M;
  rep(i, M) {
    int x, y;
    cin >> x >> y;
    x--;y--;
    v[x].push_back(y);
  }
  cin >> S >> T;
  S--;T--;
  rep(i, N) {
    rep(j, 3) {
      dist[i][j] = INF;
    }
  }
  queue<P> que;
  que.push(make_pair(S, 0));
  dist[S][0] = 0;
  while(que.size()) {
    P p = que.front();
    que.pop();
    // cout << p.first << " " << p.second << endl;

    rep(i, v[p.first].size()) {
      // cout << v[p.first][i] << endl;
      if(dist[v[p.first][i]][(p.second+1) % 3] > dist[p.first][p.second] + 1) {
        dist[v[p.first][i]][(p.second+1) % 3] = dist[p.first][p.second] + 1;
        P np = make_pair(v[p.first][i], (p.second + 1) % 3);
        que.push(np);
        // cout << np.first << " " << np.second << endl;
      }
    }
  }
  if(dist[T][0] == INF) cout << -1 << endl;
  else cout << dist[T][0] / 3 << endl;
  // rep(i, N) {
  //   rep(j, v[i].size()) {
  //     cout << v[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  return 0;
}