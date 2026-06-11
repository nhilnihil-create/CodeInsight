#include <iostream>
using namespace std;

int main(){
	int n;
	while(cin >> n,n){
		int dp[31]={0};
		dp[0] = 1;
		for(int i=0;i<=n;i++)
			for(int j=1;j<=3 && i+j <= n;j++)
				dp[i+j] += dp[i];
		cout << (dp[n]+3649)/3650 << endl;
	}
	
}