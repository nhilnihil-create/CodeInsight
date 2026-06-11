#include <bits/stdc++.h>
using namespace std;

class UnionFind {
  vector<int> P, S;
public:
  UnionFind(int n) : P(n), S(n, 1) {
    iota(P.begin(), P.end(), 0);
  }
  int root(int x) {
    if (P.at(x) == x) return x;
    else return P.at(x) = root(P.at(x));
  }
  void unit(int x,int y) {
    x = root(x), y = root(y);
    if (x == y) return;
    if (S.at(x) < S.at(y)) swap(x, y);
    P.at(y) = x;
    S.at(x) += S.at(y);
  }
  int size(int x) {
    x = root(x);
    return S.at(x);
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  UnionFind UF(N);
  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    A--, B--;
    UF.unit(A, B);
  }
  int mx = 0;
  for (int i = 0; i < N; i++) {
    mx = max(mx, UF.size(i));
  }
  cout << mx << "\n";
}