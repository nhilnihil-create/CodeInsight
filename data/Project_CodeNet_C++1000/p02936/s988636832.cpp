#include <bits/stdc++.h>
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
using namespace std;

int Qsum[200005];
int Csum[200005];
vector<int> edges[200005];
bool visited[200005];

void dfs(int v, int q) {
  if(visited[v]) return;
  visited[v] = true;
  Csum[v] = q;
  rep(i, edges[v].size()) {
    dfs(edges[v][i], q+Qsum[edges[v][i]]);
  }
}

int main() {
  int N, Q;
  cin >> N >> Q;
  int a,b,p,x;
  rep(i, N-1) {
    cin >> a >> b;
    a--; b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  rep(i, Q) {
    cin >> p >> x;
    p--;
    Qsum[p] += x;
  }
  dfs(0, Qsum[0]);
  rep(i, N-1) {
    cout << Csum[i] << " " << flush;
  }
  cout << Csum[N-1] << endl;
  return 0;
}
