#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 1e5+5;
ll dp[N];
void solve(){
	int n; 
	cin>>n; 
	dp[0] = 1;
	for(int i=3;i<=n;i++){
		for(int j=i-3;j>=0;j--){
			dp[i] += dp[j];
			dp[i] %= mod;
		}
	}
	cout<<dp[n]<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 
//	cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}
