#include <bits/stdc++.h>
using namespace std;


struct UnionFindTree {
    vector<int> size, parents;
    
    UnionFindTree() {}
    UnionFindTree(int n) {
        size.resize(n, 0);
        parents.resize(n, 0);
        for (int i = 0; i < n; i++) { makeTree(i); }
    }
    
    void makeTree(int x) {
        parents[x] = x;
        size[x] = 1;
    }
    
    bool isSame(int x, int y) { return findRoot(x) == findRoot(y); }
    
    bool unite(int x, int y) {
        x = findRoot(x);
        y = findRoot(y);

        if (x == y) return false;
        if (size[x] > size[y]) {
            parents[y] = x;
            size[x] += size[y];
        } else {
            parents[x] = y;
            size[y] += size[x];
        }
        return true;
    }
    
    int findRoot(int x) {
        if (x != parents[x]) { parents[x] = findRoot(parents[x]); }
        return parents[x];
    }
    
    int treeSize(int x) { return size[findRoot(x)]; }
};



int main() {

  int N, M;
  scanf("%d %d", &N, &M);

  vector<int> A(M);
  vector<int> B(M);

  for (int i=0;i<M;i++){
    scanf("%d %d", &A[i], &B[i]);
  }
  
  UnionFindTree uf(N+1);

  int MAX_TREE=1;
  for (int i=0;i<M;i++){
    uf.unite(A[i], B[i]);
    MAX_TREE = max(MAX_TREE, max(uf.treeSize(A[i]), uf.treeSize(B[i])));
  }

  printf("%d\n", MAX_TREE);
  
  return 0;
}

