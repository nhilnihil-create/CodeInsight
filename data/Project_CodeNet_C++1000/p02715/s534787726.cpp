#include <bits/stdc++.h>
using namespace std;
#define dhoom ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);  
typedef long long ll;
typedef long double ld;
const ll inf = 1e18;
const int nax = 2e6 + 7;
const ll mod = 1e9 + 7;
//ll tree[4 * nax];
//9uS-22RSwk7gQqh
//int t[100005] , x[100005] , y[100005];
ll exp(ll a , ll b){
	if(b == 0)	return 1;
	int x = b % 2 == 0 ?   ((exp(a , b/2)%mod)*(exp(a , b / 2)%mod))%mod :  (a%mod*exp(a , b - 1) % mod)%mod;
	return x;
}
ll dp[nax];
int main(){
	dhoom;
	ll n , k;
	cin >>n >> k;
	ll ans = 0;
	for(int i = k ; i >= 1 ; i--){
		dp[i] = (k / i); // that much multiples are there for i 
		dp[i] = exp(dp[i],n);
		for(int j = 2 * i ; j <= k ; j+=i){
			dp[i] = (dp[i] - dp[j] + mod)%mod;
		}
	//	cout << dp[i] << " " << i << endl;
		ans = ans + dp[i]*i;
		//cout << ans << endl;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
	
}