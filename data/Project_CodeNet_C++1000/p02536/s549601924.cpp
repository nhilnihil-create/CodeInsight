#include <iostream>
#include <vector>

using namespace std;
struct UnionFind{
      vector<int> par;
      
      UnionFind(int N):par(N){
            for(int i = 0;i < N;i++){
                  par[i] = i;
            }
      }
      int root(int x){
            if(x == par[x]){
                  return x;
            }
            return par[x] = root(par[x]);
      }
      
      void unite(int x,int y){
            int rx = root(x);
            int ry = root(y);
            if(rx == ry)return;
            par[rx] = ry;
      }
      bool same(int x,int y){
            return root(x) == root(y);
      }
};

int main(void){
    int n,m;
    cin >> n >> m;
    UnionFind UT(n);
    for(int i = 0;i < m;i++){
          int a,b;
          cin >> a >> b;
          a--;b--;
          UT.unite(a,b);
    }
    int ans = 0;
    for(int i = 0;i < n;i++){
          if(!UT.same(0,i)){
                ans++;
                UT.unite(0,i);
          }
    }
    cout << ans << endl;
}
