#include<bits/stdc++.h>
using namespace std;
int M,D,dp[105][105];
int main(){
	for(int i=22;i<=99;i++){
		if(i%10>=2)
			dp[(i/10)*(i%10)][i]++;
	}
	int ans=0;
	while(cin>>M>>D){
	ans=0;	
	for(int i=4;i<=M;i++)
		for(int j=22;j<=D;j++)
			ans+=dp[i][j];
	cout<<ans;}
}