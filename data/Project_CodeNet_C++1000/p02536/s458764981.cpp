#include <bits/stdc++.h>
#define Rep(i,j,n) for(int i=j; i<n; i++)
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100//000000000
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
#define PP pair<int,P>
#define T tuple<int,int,int> 
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



int main(){
  int n,m; cin >> n >> m;
  UnionFind u(n);
  rep(i,m){
    int a,b; cin >> a >> b;
    a--; b--;
    u.unite(a,b);
  }
  vector<int> ans(n+1,0);
  rep(i,n){
    ans[u.find(i)]++;
  }

  int Ans=0;
  rep(i,n){
    if(ans[i]) Ans++;
  }

  cout << Ans-1 << endl;
  return 0;
}