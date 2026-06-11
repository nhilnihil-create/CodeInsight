#include <bits/stdc++.h>
using namespace std;
struct UnionFind {
    vector<int> par, size;
    UnionFind(int x) {
        par.resize(x);
        size.resize(x, 1);
        for (int i = 0; i < x; i++) {
            par[i] = i;
        }
    }
    int find(int x) {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int consize(int x) {
        return size[find(x)];
    }
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;
        if (size[x] < size[y]) {
            par[x] = y;
            size[y] += size[x];
        }
        else {
            par[y] = x;
            size[x] += size[y];
        }
    }
};
int main(){
  int N,M;cin>>N>>M;
  UnionFind Onion(N);
  for(int i=0;i<M;i++){
    int a,b,c;cin>>a>>b>>c;
    if(a==0)Onion.unite(b,c);
    else cout<<(Onion.same(b,c)? 1:0)<<endl;
  }
}