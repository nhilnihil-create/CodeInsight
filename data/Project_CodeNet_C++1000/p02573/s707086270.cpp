#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};

struct UnionFind {
    //自身が親であれば、その集合に属する頂点数に-1を掛けたもの
    //そうでなければ親のid
    vector<int> r;

    UnionFind(int N) {
        r = vector<int>(N, -1);
    }

    int root(int x) {
        if (r[x] < 0) return x;
        return r[x] = root(r[x]);
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x, y);
        r[x] += r[y];
        r[y] = x;
        return true;
    }

    int size(int x) {
        return -r[root(x)];
    }
};

int main(void){
  int N, M;
  cin >> N >> M;

  UnionFind UF(N);
  rep(i,M){
    int A, B;
    cin >> A >> B;
    A --; B --;
    UF.unite(A, B);
  }

  int ans = 0;
  rep(i,N) ans = max(ans, UF.size(i));


  cout << ans << endl;
  return 0;
}
