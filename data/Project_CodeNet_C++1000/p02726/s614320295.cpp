#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<n; i++)
#define repr(i,n,m) for(long long i=m; i<n; i++)
#define mod 1000000007
#define sorti(x) sort(x.begin(), x.end())
#define sortd(x) sort(x.begin(), x.end(), std::greater<long long>())
#define debug(x) std::cerr << (x) << std::endl;
#define roll(x) for (auto&& itr : x) { cerr << (itr) << " "; }

template <class T> inline void chmax(T &ans, T t) { if (t > ans) ans = t;}
template <class T> inline void chmin(T &ans, T t) { if (t < ans) ans = t;}

template <class T>
T inf = numeric_limits<T>::max();

vector<int> dist;

void bfs(vector<vector<int>> const& G, int start, vector<bool>& visited) {
  queue<int> que;
  que.push(start);
  dist[start] = 0;

  while (!que.empty()) {
    auto now = que.front();
    que.pop();
    visited[now] = true;

    for (auto to : G[now]) {
      if (visited[to] || dist[to] != 0) continue;
      dist[to] = dist[now]+1;
      que.push(to);
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N,X,Y;
  cin >> N >> X >> Y;
  X--, Y--;

  vector<vector<int>> G(N);
  repr(i, N-1, 0) {
    G[i].push_back(i+1);
    G[i+1].push_back(i);
  }

  G[X].push_back(Y);
  G[Y].push_back(X);

  map<int,int> mp;
  
  dist.resize(N+1, 0);
  for (int i = 0; i < N-1; ++i) {
    vector<bool> visited(N);
    bfs(G, i, visited);

    for (int j = i+1; j < N; ++j) {
      mp[dist[j]] += 1;
    }

    for (auto& itr : dist) itr = 0;
  }

  for (int i = 1; i < N; ++i) {
    cout << mp[i] << endl;
  }
}
