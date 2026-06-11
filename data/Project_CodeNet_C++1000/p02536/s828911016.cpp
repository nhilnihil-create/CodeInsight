#include <bits/stdc++.h>
using namespace std;

class UnionFind {
private:
  int N;
  vector<int> PS;

public:
  UnionFind() : N(0) {}
  UnionFind(int n) : N(n), PS(n, -1) {}
  bool unite(int a, int b) {
    int x = root(a), y = root(b);
    if (x == y) return false;
    if (-PS.at(x) < -PS.at(y)) swap(x, y);
    PS.at(x) += PS.at(y);
    PS.at(y) = x;
    return true;
  }
  bool same(int a, int b) { return root(a) == root(b); }
  int root(int a) {
    if (PS.at(a) < 0) return a;
    return PS.at(a) = root(PS.at(a));
  }
  int size(int a) { return -PS.at(root(a)); }
  vector<vector<int>> groups() {
    vector<int> B(N), S(N);
    for (int i = 0; i < N; i++) {
      B.at(i) = root(i);
      S.at(B.at(i))++;
    }
    vector<vector<int>> ret(N);
    for (int i = 0; i < N; i++) {
      ret.at(i).reserve(S.at(i));
    }
    for (int i = 0; i < N; i++) {
      ret.at(B.at(i)).push_back(i);
    }
    auto f = [&](const vector<int> &v) { return v.empty(); };
    ret.erase(remove_if(ret.begin(), ret.end(), f), ret.end());
    return ret;
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  UnionFind UF(N);
  int cnt = N;
  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B, A--, B--;
    cnt -= UF.unite(A, B);
  }
  cout << cnt - 1 << "\n";
}