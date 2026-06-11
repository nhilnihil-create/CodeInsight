#include<bits/stdc++.h>

struct UnionFind {
    std::vector<int> data;

    UnionFind(int n=1e5): data(n, -1) {}

    int root(int x){
        if(data[x]<0) return x;
        else return data[x] = root(data[x]);
    }

    void unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x==y) return;
        data[x] += data[y];
        data[y] = x;
    }
};

int main(){
  int n, q, p, a, b;
  scanf("%d %d", &n, &q);
  UnionFind uf(n);
  for(int i=0; i<q; i++){
    scanf("%d %d %d", &p, &a, &b);
    if(p==0) uf.unite(a, b);
    else{
      if(uf.root(a)==uf.root(b)){
        puts("1");
      }else{
        puts("0");
      }
    }
  }
  return 0;
}
