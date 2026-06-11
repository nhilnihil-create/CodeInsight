#include<bits/stdc++.h>
using namespace std;

int dp[10005];

int main(){
	int h,n;
	cin>>h>>n;
	vector< pair<int,int> > yoyo(n);
	for(int i=0;i<n;i++){
		cin>>yoyo[i].first>>yoyo[i].second;
	}
	
	dp[0]=0;
	for(int i=1;i<h+1;i++)dp[i]=2e8;
	
	
	for(int i=0;i<n;i++){
		for(int j=1;j<h+1;j++){
			if(j<=yoyo[i].first) {
				dp[j]=min(yoyo[i].second,dp[j]);
			}
			else dp[j]=min(dp[j],yoyo[i].second+dp[j-yoyo[i].first]);
		}
	}
	
	
	cout<<dp[h]<<endl;
	
}