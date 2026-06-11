#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
const int mod=1e9+7;

int main()
{
	vector<int> dp(2020);
	int s;cin>>s;dp[0]=1;
	for(int i=0;i<=s;i++){
		for(int j=3;j+i<=s;j++) dp[i+j]=(dp[i+j]+dp[i])%mod;
	}
	cout<<dp[s]%mod;
	return 0;	
} 