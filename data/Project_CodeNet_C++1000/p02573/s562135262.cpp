#include <bits/stdc++.h>
using namespace std;
template<class C>constexpr int sz(const C&c){return int(c.size());}
using ll=long long;constexpr const char nl='\n',sp=' ';

struct UnionFind {
  vector<int> UF; int cnt; UnionFind(int N) : UF(N, -1), cnt(N) {}
  int find(int v) { return UF[v] < 0 ? v : UF[v] = find(UF[v]); }
  bool join(int v, int w) {
    if ((v = find(v)) == (w = find(w))) return false;
    if (UF[v] > UF[w]) swap(v, w);
    UF[v] += UF[w]; UF[w] = v; cnt--; return true;
  }
  bool connected(int v, int w) { return find(v) == find(w); }
  int getSize(int v) { return -UF[find(v)]; }
};

int main() {
  // freopen("in.txt", "r", stdin);
  // freopen("out.txt", "w", stdout);
  // freopen("err.txt", "w", stderr);
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int N, M;
  cin >> N >> M;
  UnionFind uf(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    uf.join(--a, --b);
  }
  int ans = 1;
  for (int i = 0; i < N; i++) ans = max(ans, uf.getSize(i));
  cout << ans << nl;
  return 0;
}
