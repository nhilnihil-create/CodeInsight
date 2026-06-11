#include <bits/stdc++.h>
using namespace std;
const int N=1000000000;
int main() {
	int n, m;
	cin>>n>>m;
	int cost[m];
	int mask[m];
	for(int i=0; i<m; i++){
		int a, b;
		cin>>a>>b;
		cost[i]=a;
		int num=0;
		for(int j=0; j<b; j++){
			int x;
			cin>>x;
			x--;
			num+=(1<<x);
		}
		mask[i]=num;
	}
	
	int dp[m][(1<<n)];
	for(int i=0; i<m; i++){
		for(int j=0; j<(1<<n); j++){
			dp[i][j]=N;
		}
	}
	dp[0][0]=0;
	dp[0][mask[0]]=cost[0];
	
	for(int i=1; i<m; i++){
		for(int j=0; j<(1<<n); j++){
			if(dp[i-1][j]==N){
				continue;
			}
			
			dp[i][j]=min(dp[i-1][j], dp[i][j]);
			
			dp[i][(j|(mask[i]))]=min(dp[i][(j|(mask[i]))], dp[i-1][j]+cost[i]);
			
		}
	}
	if(dp[m-1][(1<<n)-1]==N){
		cout<<-1;
		return 0;
	}
	cout<<dp[m-1][(1<<n)-1];
	return 0;
}