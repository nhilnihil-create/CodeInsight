#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	vector<bool>dp(101000);
	int x;
	cin>>x;
	for(int i=100;i<=105;i++) dp[i]=true;
	for(int i=100;i<100001;i++){
		if(dp[i]==true){
			dp[i+100]=true;
			dp[i+101]=true;
			dp[i+102]=true;
			dp[i+103]=true;
			dp[i+104]=true;
			dp[i+105]=true;
		}
	}
	cout<<dp[x]<<endl;
	return 0;
}
