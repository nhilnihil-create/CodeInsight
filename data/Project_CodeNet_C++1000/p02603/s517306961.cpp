#include<bits/stdc++.h>
using ll = long long;
using namespace std;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;cin >> n;
	ll a[81];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	ll dp[81];
	dp[0] = 1000;
	for(int i = 1; i < n; i++){
		dp[i] = dp[i-1];
		for(int j = 0; j < i; j++){
			ll mai = dp[j]/a[j];
			if(a[i]*mai+dp[j]-a[j]*mai > dp[i]){
				dp[i] = a[i]*mai+dp[j]-a[j]*mai;
			} 
		}
	}
	cout << dp[n-1] << endl;
	return 0;
}
