#include <iostream>
 
using namespace std;
typedef long long ll;
int main(){
  	ll n;
  	ll mod = 1000000007;
	ll dp[2005] = {0};
	dp[0] = 1;
	
	cin >> n;
	for (ll i = 0; i < n; i++) {
		for (ll j = i + 3; j <= n; j++) {
			dp[j] = (dp[j] + dp[i]) % mod;
		}
	}
	
	cout << dp[n] << '\n';
  
}
