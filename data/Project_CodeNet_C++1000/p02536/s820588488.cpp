#include<bits/stdc++.h>
using namespace std;
vector<int>par;
void init(int N) {
  par.resize(N + 3);
  for(int i = 0; i <= N; i ++) {
    par[i] = i;
  }
}
int root(int v) {
  if (v == par[v]) return v;
  return par[v] = root(par[v]);
}
bool merge(int a, int b) {
  a = root(a);
  b = root(b);
  if (a == b) return false;
  par[b] = a;
  return true;
}
int main () {
  int N, M;
  cin >> N >> M;
  init(N);
  int ans = N - 1;
  for (int i = 0; i < M; i ++) {
    int a, b;
    cin >> a >> b;
    if (merge(a, b)) ans --;
  }
  cout << ans << endl;
}
