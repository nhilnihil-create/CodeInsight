#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

int N,M;
vector<int> R[100010];
int dist[100010];
bool f1[100010];
bool f2[100010];
bool f3[100010];
int S,T;

void BFS() {
  queue<P> q;
  q.push(make_pair(S,0));

  while (!q.empty()) {
    P p = q.front();
    q.pop();
    for (int i = 0; i < R[p.first].size(); i++) {
      if (f1[R[p.first][i]]) {
        continue;
      } else {
        f1[R[p.first][i]] = true;
      }
      for (int j = 0; j < R[R[p.first][i]].size(); j++) {
        if (f2[R[R[p.first][i]][j]]) {
          continue;
        } else {
          f2[R[R[p.first][i]][j]] = true;
        }
        for (int k = 0; k < R[R[R[p.first][i]][j]].size(); k++) {
          if (f3[R[R[R[p.first][i]][j]][k]]) {
            continue;
          } else {
            f3[R[R[R[p.first][i]][j]][k]] = true;
          }
          if (dist[R[R[R[p.first][i]][j]][k]] == 99999999) {
            dist[R[R[R[p.first][i]][j]][k]] = p.second + 1;
            q.push(make_pair(R[R[R[p.first][i]][j]][k],p.second + 1));
          }
        }
      }
    }
  }
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int u,v;
    cin >> u >> v;
    u--; v--;
    R[u].push_back(v);
  }
  cin >> S >> T;
  S--; T--;
  for (int i = 0; i < 100010; i++) dist[i] = 99999999;
  BFS();

  if (dist[T] == 99999999) {
    cout << -1 << endl;
  } else {
    cout << dist[T] << endl;
  }
  return 0;
}