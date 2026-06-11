#include <bits/stdc++.h>
#define ll long long
#define mod (ll)(1e9 + 7)
using namespace std;

ll sub(ll a, ll b){
	ll r = (a - b)%mod;
	r += mod;
	r %= mod;
	return r;
}

ll add(ll a, ll b){
	return (a + b)%mod;
}

ll mul(ll a, ll b){
	return a * b % mod;
}

ll my_pow(ll a, ll b){
	// a^b
	ll res = 1LL;
	while(b){
		if(b&1) res = mul(res,a);
		a = mul(a,a);
		b = b / 2;
	}
	return res;
}

int main() {
	// your code goes here
	ll S;
	cin>>S;
	vector <ll> dp(S+1,1LL); 
	if(S<3){
		cout<<"0\n";
		return 0;
	}
	
	dp[0] = 0; dp[1] =0; dp[2] = 0;
	
	//dp[i] = sum {dp[i - j]} j>=3
	dp[3] = 1LL;
	for(int i=3;i<=S;++i){
		for(int j=3;j+i<=S;++j){
			dp[i+j] = add(dp[i+j],dp[i]);
		}
	}
	cout<<dp[S]<<"\n";
	return 0;
}