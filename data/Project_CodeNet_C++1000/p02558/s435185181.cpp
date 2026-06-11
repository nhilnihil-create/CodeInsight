#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;


struct UnionFind {
  vector<int> data;
  UnionFind(int size) : data(size, -1) { }
  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool findSet(int x, int y) {
    return root(x) == root(y);
  }
  int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  int size(int x) {
    return -data[root(x)];
  }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int N, Q; cin >> N >> Q;
    UnionFind uf(N);
    for(int i = 0; i < Q; i++){
        int t, u, v; cin >> t >> u >> v;
        if(t == 0){
            uf.unionSet(u, v);
        }else{
            cout << (uf.findSet(u, v) ? 1 : 0) << endl;
        }
    }
}