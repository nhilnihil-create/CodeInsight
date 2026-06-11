#include<bits/stdc++.h>
#include<atcoder/dsu>
using namespace std;
using namespace atcoder;
int main(){
  int n;
  cin >> n;
  dsu d(n);
  int q;
  cin >> q;
  while(q--){
    int t, a, b;
    cin >> t >> a >> b;
    if(t == 0){
      d.merge(a, b);
    }else{
      if(d.same(a, b))
        cout << 1;
      else
        cout << 0;
      cout << "\n";
    }
  }
  return 0;
}
