#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
const int N=2e6+2;
int dp[N][2];
string s;int n;
int solve(int idx, int c)
{
	if(idx==n)return c;
	int &ret=dp[idx][c];
	if(ret!=-1)return ret;
	int val=s[idx]-'0';val+=c;
	ret=1e9;
	if(val<10)ret=min(ret,solve(idx+1,0)+val);
	ret=min(ret,solve(idx+1,1)+10-val);
	return ret;
}
int32_t main()
{
	#ifndef ONLINE_JUDGE
		freopen("in","r",stdin);
		freopen("out","w",stdout);
	#endif
	cin>>s;n=s.size();
	reverse(s.begin(),s.end());
	memset(dp,-1,sizeof dp);
	cout<<solve(0,0);


}