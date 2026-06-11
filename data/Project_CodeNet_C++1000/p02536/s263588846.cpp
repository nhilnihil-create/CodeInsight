#include<bits/stdc++.h>
#include <atcoder/all>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
using namespace atcoder;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

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

int main() {
    int n,m;
    cin >> n >> m;
    UnionFind uf(n);
    rep(i,m) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        uf.unite(a,b);
    }
    set<int>se;
    rep(i,n) se.insert(uf.find(i));
    int ans = se.size()-1;
    cout << ans << endl;
}