#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
const lint MOD = 1e9+7;

lint modpow(lint m, lint n){
  if(n == 0) return 1;
  else if(n % 2 == 0) return modpow(m * m % MOD, n/2);
  else{
    return modpow(m, n - 1) * m % MOD;
  }
}

signed main(){
	lint N, K; cin >> N >> K;
	lint ans = 0;
	vector<lint> data(K + 1, 0);
	for(lint i = K; i > 0; i--){
		lint num = modpow(K/i, N);
		for(lint j = 2 * i; j <= K; j += i){
			num = num - data[j] + MOD;
			num %= MOD;
		}
		data[i] = num;
		ans += num * i;
		ans %= MOD;
	}
	cout << ans << endl;
}
