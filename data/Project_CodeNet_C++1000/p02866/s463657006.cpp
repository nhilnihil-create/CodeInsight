#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint MOD = 998244353;

lint modpow(lint m, lint n){
  if(n == 0) return 1;
  else if(n % 2 == 0) return modpow(m * m % MOD, n/2);
  else{
    return modpow(m, n - 1) * m % MOD;
  }
}

signed main(){
  lint N; cin >> N;
  vector<lint> a(N), num(N);
  for(lint i = 0; i < N; i++) {cin >> a[i]; num[a[i]]++;};
  if(a[0] != 0 || num[0] != 1){
    cout << 0 << endl;
    return 0;
  }
  lint ans = 1;
  for(lint i = 2; i < N; i++){
     ans *= modpow(num[i - 1], num[i]);
     ans %= MOD;
  }
  cout << ans << endl;
}
