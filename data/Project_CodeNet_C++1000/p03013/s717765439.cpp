#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sidha(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int> 
#define pb push_back
#define mod 1000000007

int solve(int n){
	int dp[n+1];
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<n+1;i++){
		dp[i]=(dp[i-1]+dp[i-2])%mod;
	}
	return dp[n];
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
	int n,m;cin>>n>>m;
	vector<int> arr(n+1,true);
	for(int i=0;i<m;i++){
		int a;cin>>a;
		arr[a]=false;
	}
	vector<ll> dp(n+1);
	dp[0]=1;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=min(n,i+2);j++){
			if(arr[j]){
				dp[j]+=dp[i];
				dp[j]%=mod;
			}
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}