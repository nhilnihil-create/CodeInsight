#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int N=3005;
const int mod=998244353;
ll dp[N][N];
int a[N];

void solve(){
	int n,s;
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=s;j>=0;j--){
			dp[i][j]=dp[i-1][j]*2;
			dp[i][j]%=mod;
			if(a[i]+j<=s){
				dp[i][j+a[i]]+=dp[i-1][j];
				dp[i][j+a[i]]%=mod;
				}
			}
			
		}
	cout<<dp[n][s]<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t;
	while(t--)solve();
}
