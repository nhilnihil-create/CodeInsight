#include <algorithm>
#include <iostream>
#include <queue>

#define MAXN 10000
#define MAXM 100000

using namespace std;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  struct {
    int to, next;
  } E[MAXM];
  vector<int> LE(MAXN, -1);

  int n, m;
  cin >> n >> m;
  for (int i = 0, s, t; i < m; ++i) {
    cin >> s >> t;
    E[i] = {t, LE[s]};
    LE[s] = i;
  }

  int indegree[MAXN]{0};
  for (int e = 0; e < m; ++e)
    ++indegree[E[e].to];

  queue<int> sources;
  for (int i = 0; i < n; ++i)
    if (indegree[i] == 0)
      sources.push(i);

  int seen = 0;
  while (seen < n) {
    int curr = sources.front();
    sources.pop();
    ++seen;
    cout << curr << endl;
    for (int e = LE[curr]; e != -1; e = E[e].next) {
      --indegree[E[e].to];
      if (indegree[E[e].to] == 0)
        sources.push(E[e].to);
    }
  }
}
