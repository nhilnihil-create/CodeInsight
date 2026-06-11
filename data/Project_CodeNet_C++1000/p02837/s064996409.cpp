#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  
  int n;
  cin >> n;
  vector<int> v(n,0);
  vector<int> mask(n,0);
  rep(i,n){
    int a;
    cin >> a;
    rep(j,a){
      int x,y;
      cin >> x >> y;
      x --;
      v[i] |= (y << x);
      mask[i] |= (1 << x);
    }
  }
  int ans = 0;
  rep(i,(1 << n)){
    int bits = 0;
    rep(j,n){
      bool bit = (i >> j)&1;
      bits += bit;
      if(bit){
        int check = i^v[j];
        check &= mask[j];
        if(check > 0) break;
      }
      if(j == n-1) ans = max(ans,bits);
    }//j
  }//i
  cout << ans << endl;
}