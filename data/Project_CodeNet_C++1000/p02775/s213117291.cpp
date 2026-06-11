#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[10000000][2];

signed main(){
	string S; cin>>S;
	int ans=0,N=S.size();
	dp[1][0]=S[0]-'0';
	dp[1][1]=10-(S[0]-'0');
	for(int i=1;i<N;i++){
		int t=S[i]-'0';
		dp[i+1][0]=min(dp[i][0]+t , dp[i][1]+t+1);
		dp[i+1][1]=min(dp[i][0]+10-t , dp[i][1]+10-(t+1));
	}
	cout<<min(dp[N][0],dp[N][1]+1)<<endl;

}