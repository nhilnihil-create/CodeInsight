#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
int main(){
  int n;
  cin >> n;
  vector<int> v(n),mask(n);
  rep(i,n){
    int a;
    cin >> a;
    rep(j,a){
      int x,y;
      cin >> x >> y;
      v[i] |= (y << x-1);
      mask[i] |= (1 << x-1);
    }
  }
  int ans = 0;
  rep(i,(1<<n)){
    rep(j,n){
      bool bit = (i>>j)&1;
      if(bit){
        int check = (i^v[j])&mask[j];
        if(check > 0) break;
      }
      if(j == n-1)ans = max(ans,__builtin_popcount(i));
    }
  }
  cout << ans << endl;
}