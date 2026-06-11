#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll mod = 1000000007;

ll dp[100005];

ll fast_pow(ll val, ll pw){
	if(pw == 0)
		return 1;
	ll tmp = fast_pow(val, pw/2), ans;
	ans = (tmp*tmp)%mod;
	if(pw%2==1)
		ans = (ans*val)%mod;
	return ans;
}

ll num_div(int n, int maxi, int pw){
	ll prod;
	int tmp = maxi/n;
	prod = fast_pow(tmp, pw);
	return prod;
}

int main(){
	int n, k;
	ll sum = 0;
	cin>>n>>k;
	memset(dp, 0, sizeof dp);
	for(int x=k;x>=1;x--){
		dp[x] = num_div(x, k, n)%mod;
		for(int div=2;div*x<=k;div++){
			dp[x] = (dp[x]-dp[x*div])%mod;
			while(dp[x] < 0){
				dp[x] += mod;
			}
		}
		sum = (sum+(x*dp[x])%mod)%mod;
		//cout<<x<<" "<<dp[x]<<"\n";
	}
	cout<<sum<<"\n";
	return 0;
}