#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <algorithm>
#define shosu(x) fixed<<setprecision(x)
using namespace std;

int n,w,inf=-1,wei[105],val[105],dp[105][10005];

int func(){
	for(int i=0;i<n;i++){
		for(int j=0;j<=w;j++){
			if(j<wei[i]) dp[i+1][j]=dp[i][j];
			else dp[i+1][j]=max(dp[i][j],dp[i][j-wei[i]]+val[i]);
		}
	}
	return dp[n][w];
}

int main(){
	cin>>n>>w;
	for(int i=0;i<n;i++){
		cin>>val[i]>>wei[i];
	}
	cout<<func()<<endl;
}