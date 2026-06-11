#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
const int64_t INF = (1LL << 62);
vector<int64_t> to[MAXN];
vector<vector<int64_t>> steps(3, vector<int64_t>(MAXN, INF));

int main()
{
  int64_t N, M, u, v, S, T;
  cin >> N >> M;
  for (int i = 0; i < M; i++)
  {
    cin >> u >> v;
    u--, v--;
    to[u].push_back(v);
  }
  cin >> S >> T;
  S--, T--;
  queue<pair<int64_t, int64_t>> Q;
  Q.push({S, 0});
  while (Q.size())
  {
    int64_t cur = Q.front().first, step = Q.front().second;
    Q.pop();
    for (auto v : to[cur])
    {
      if (steps[(step + 1) % 3][v] != INF)
        continue;
      steps[(step + 1) % 3][v] = step + 1;
      Q.push({v, step + 1});
    }
  }
  cout << (steps[0][T] == INF ? -1 : steps[0][T] / 3) << endl;
}