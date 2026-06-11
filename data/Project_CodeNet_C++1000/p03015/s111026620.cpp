#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

ll dp[100010][2];
int main() {
	string s;
	cin>>s;
	dp[0][0]=1;//0は未満未確定
	for(ll i=0;i<s.size();i++){
		if(s[i]=='0'){
			dp[i+1][0]+=dp[i][0];//0しか選択できない
			dp[i+1][1]+=dp[i][1];//０を選択
			dp[i+1][1]+=(dp[i][1]*2)%inf;//1を選択
		}
		else{//１のとき
			dp[i+1][1]+=dp[i][0];//0を選択
			dp[i+1][0]+=(dp[i][0]*2)%inf;//１を選択
			dp[i+1][1]+=dp[i][1];//0を選択
			dp[i+1][1]+=(dp[i][1]*2)%inf;//１を選択
		}
		dp[i+1][0]%=inf;
		dp[i+1][1]%=inf;
	}
	cout << (dp[s.size()][1]+dp[s.size()][0])%inf;
	// your code goes here
	return 0;
}