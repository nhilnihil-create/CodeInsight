#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	int n;
	while(cin>>n&&n!=0){
		int num[5001];
		for(int i = 0; i < n; i++){
			cin>>num[i];
		}
		
		int dp[5001];
		dp[0]=num[0];
		int maxNum=(
			dp[0]);
		for(int i = 1; i < n; i++){
			dp[i]=max(num[i],dp[i-1]+num[i]);
			maxNum=max(maxNum,dp[i]);
		}
		cout<<maxNum<<endl;
		
	}

	return 0;
}