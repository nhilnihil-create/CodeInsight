#include <bits/stdc++.h>
using namespace std;
long long dp[60][200005];
int main(){
	long long n,k;
    cin>>n>>k;
	for(int i=0;i<n;i++) {
        cin>>dp[0][i];
        dp[0][i]--;
    }
	for(int i=0;i<59;i++) {
		for(int j=0;j<n;j++) {
			dp[i+1][j]=dp[i][dp[i][j]];
		}
	}
	long long ans=0;
	for(int i=59;i>=0;i--){
		long long l=1ll<<i;
		if(l<=k){
			k-=l;
			ans=dp[i][ans];
		}
	}
	cout<<ans+1<<endl;
	return 0;
}
