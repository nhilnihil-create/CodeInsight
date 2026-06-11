#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x1) cout<<#x1<<": "<<x1<<endl
#define debug2(x1,x2) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<endl
#define debug3(x1,x2,x3) cout<<#x1<<": "<<x1<<", "#x2<<": "<<x2<<", "#x3<<": "<<x3<<endl

signed main(){
  int n, k; cin >> n >> k;
  int mod = 1000000007;
  int cnt = 0, left = 0, right = 0;
  for(int i=0; i<=n; i++) {
    left += i;
    right += n-i;
    if(i+1>=k){
      cnt += (right-left+1) % mod;
      cnt = cnt % mod;
    }
  }
  cout << cnt << endl;
  return 0;
}