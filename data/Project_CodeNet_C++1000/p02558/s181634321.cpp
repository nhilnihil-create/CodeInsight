#include<bits/stdc++.h>
#include<atcoder/dsu>
using namespace std;
using namespace atcoder;
int main(){
  int n, q;
  cin >> n >> q;
  dsu uf(n);
  while(q--){
    int t, x, y;
    cin >> t >> x >> y;
    if(t ==0) uf.merge(x, y);
    else cout << uf.same(x, y) << endl;
  }
}