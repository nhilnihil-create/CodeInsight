#include <iostream>
#include <cstring>
using namespace std;

unsigned long long dp[102][22];

int main(void){
	int n;
	cin>>n;
	int t[n];

	for(int i=0;i<n;i++){
		cin>>t[i];
	}
	memset(dp,0,sizeof(dp));
	dp[1][t[0]] = 1;

	for(int i=1;i<n-1;i++){
		for(int j=0;j<=20;j++){
			if(dp[i][j] > 0){
				int plus = j + t[i];
				int minus = j - t[i];

				if(plus>=0 && plus<=20){
					dp[i+1][plus] += dp[i][j];
				}
				if(minus>=0 && minus<=20){
					dp[i+1][minus] += dp[i][j];
				}
			}
		}
	}
	cout<<dp[n-1][t[n-1]]<<endl;

	return 0;
}