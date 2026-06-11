#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1e7+2;
string s;
int dp[MAX_N][2];

void solve()
{
	reverse(s.begin(), s.end());
	s += '0';
	const int n = s.length();
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=0;i<n;++i)for(int j=0;j<2;++j){
		const int req = s[i]-'0'+j;
		for(int use=0;use<10;++use){
			int borrow = 0, change = use-req;
			if(change < 0){
				change += 10;
				borrow=1;
			}
			dp[i+1][borrow]=min(dp[i+1][borrow],dp[i][j]+use+change);
		}
	}
	cout<<dp[n][0];
}

int main()
{
	cin >> s;
	solve();
	return 0;
}