#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0;i < (int)(n);i++)

int N, M;
vector<int> p, r;

void init(int n) {
  rep(i, n) {
    p[i] = i;
    r[i] = 0;
  }
}
int parent(int x) {
  if(p[x] == x) return x;
  else return p[x] = parent(p[x]);
}
void unite(int x, int y) {
  x = parent(x), y = parent(y);
  if(x == y) return;
  if(r[x] < r[y]) p[x] = y;
  else p[y] = x;
  if(r[x] == r[y]) r[x]++;
}

int main() {
  int a, b, ans = 0;
  map<int, int> m;
  cin >> N >> M;
  p.resize(N);
  r.resize(N);
  init(N);
  rep(i, M) {
    cin >> a >> b;
    a--;
    b--;
    unite(a, b);
  }
  for(auto x : p) m[parent(x)]++;
  for(auto c : m) ans = max(ans, c.second);
  cout << ans << endl;
}