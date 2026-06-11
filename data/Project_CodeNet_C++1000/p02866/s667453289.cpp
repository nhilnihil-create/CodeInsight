#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint MOD = 998244353;

signed main(){
  lint N; cin >> N;
  vector<lint> a(N), num(N, 0);
  for(lint i = 0; i < N; i++) {cin >> a[i]; num[a[i]]++;};
  if(a[0] != 0 || num[0] != 1){
    cout << 0 << endl;
    return 0;
  }
  lint ans = 1;
  for(lint i = 1; i < N; i++){
    ans *= num[a[i] - 1];
    ans %= MOD;
  }
  cout << ans << endl;
}
