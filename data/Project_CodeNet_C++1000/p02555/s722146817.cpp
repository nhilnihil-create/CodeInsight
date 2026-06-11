#include<bits/stdc++.h>
using namespace std;
long long M=1e9+7;
int solve(){
	int s;
	cin>>s;
	long long dp[s+5];
	long long sum=0; //upto i-3;
	sum=1;
	dp[0]=1;
	dp[1]=0;
	dp[2]=0;
	for(int i=3;i<=s;i++){
		dp[i]=sum;
		sum=(sum+dp[i-2])%M;
	}
	return dp[s];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<solve()<<"\n";
}