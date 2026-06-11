#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 2e5+6;
int dp[N];
int a[N];
int b[N];
void solve(){
	memset(dp,0x3f,sizeof dp);
	int h,n; 
	cin>>h>>n; 
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	dp[0] = 0;
	for(int i=1;i<=1e4+h;i++){
		for(int j=1;j<=n;j++){
			if(i>=a[j]){
				dp[i] = min(dp[i],dp[i-a[j]]+b[j]);
			}
		}
	}
	int ans = 1e9;
	for(int i=h;i<1e4+h;i++)ans =min(ans,dp[i]);
	cout<<ans<<endl;
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
