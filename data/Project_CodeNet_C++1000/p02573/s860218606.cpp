#include<iostream>
#include<vector>
using namespace std;

struct UnionFind {
  vector<int> r;

  UnionFind(int N) {
    r = vector<int>(N, -1);
  }

  int getRoot(int x) {
    if (r[x] < 0) return x;
    return r[x] = getRoot(r[x]);
  }

  void unite(int x, int y) {
    int rx = getRoot(x);
    int ry = getRoot(y);
    if (rx == ry) return;

    r[rx] += r[ry];
    r[ry] = rx;
  }

  int size(int x) {
    return -r[getRoot(x)];
  }
};

int main() {
  int N,M,i,a,b;
  cin>>N>>M;
  UnionFind UF(N);
  for (i=0;i<M;i++) {
    cin>>a>>b;
    UF.unite(a-1,b-1);
  }
  int ans=0;
  for (i=0;i<N;i++) {
    ans = max(ans,UF.size(i));
  }
  cout<<ans<<endl;
  return 0;
}
