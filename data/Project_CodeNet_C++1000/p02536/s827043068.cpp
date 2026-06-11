#include <string>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;

struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};

int main()
{
  int n, m;
  cin >> n >> m;
  UnionFind uf(n); 
  int max_size = 0;
  int max_index = 0;
  rep(i,m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    uf.unite(a, b);
    if(max_size <= uf.size(a))
      max_size = uf.size(a);  
      max_index = a;
  }
  int maked_load = 0;
  rep(i,n){
    // cout << max_size << " " << uf.size(i) << max_index << endl;
    if(max_size == n) break;
    if(uf.size(i) == max_size) continue;
    maked_load++;
    uf.unite(i,max_index);
    max_size = uf.size(i);
  }
  cout << maked_load << endl;
}