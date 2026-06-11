#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;
const int Max_Num=1e6+10;

int main(){
	string N;
	cin >> N;
	reverse(N.begin(),N.end());
	N.push_back('0');
	int s=N.size();
	LL dp[Max_Num][2]={0};
	dp[0][0]=1;
	rep(i,s){
		int k=N[i]-'0';
		dp[i+1][1]+=min(dp[i][1]+k,dp[i][0]+k+1);
		dp[i+1][0]+=min(dp[i][1]+10-k,dp[i][0]+9-k);
	}
	cout << min(dp[s][0],dp[s][1]) << endl;

	return 0;
}