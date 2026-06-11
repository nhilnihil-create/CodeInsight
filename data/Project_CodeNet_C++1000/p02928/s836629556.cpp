#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint MOD = 1e9+7;

signed main(){
  lint N, K; cin >> N >> K;
  vector<lint> a(N);
  for(lint i = 0; i < N; i++) cin >> a[i];
  lint p = 0, q = 0, ans = 0;
  for(lint i = 0; i < N- 1; i++){
    for(lint j = i + 1; j < N; j++){
      if(a[i] > a[j]) p++;
    }
  }
  ans += p * K;
  ans %= MOD;
  for(lint i = 0; i < N; i++){
    for(lint j = 0; j < N; j++){
      if(a[i] > a[j]) q++;
    }
  }
  ans += q*((K*(K - 1)/2)%MOD);
  ans %= MOD;
  cout << ans << endl;
}