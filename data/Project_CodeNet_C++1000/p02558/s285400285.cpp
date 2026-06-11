#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;
int main(){
  int N, Q;
  cin >> N >> Q;
  dsu G(N);
  for (int i = 0; i < Q; i++){
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 0){
      G.merge(u, v);
    }
    if (t == 1){
      cout << G.same(u, v) << endl;
    }
  }
}