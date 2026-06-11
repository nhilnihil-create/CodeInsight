#include <bits/stdc++.h>
using namespace std;
char a[105][105];
int dp[105][105];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int h, w;
	cin>>h>>w;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin>>a[i][j];
			dp[i][j]=INT_MAX;
		}
	}
	if(a[1][1]=='#') dp[1][1]=1;
	else dp[1][1]=0;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(i>1) dp[i][j]=min(dp[i][j], dp[i-1][j]+(int)(a[i-1][j]=='.' && a[i][j]=='#'));
			if(j>1) dp[i][j]=min(dp[i][j], dp[i][j-1]+(int)(a[i][j-1]=='.' && a[i][j]=='#'));
		}
	}
	cout<<dp[h][w];
}