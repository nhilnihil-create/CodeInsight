#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
//typedef __int64 LL;
typedef long long int LL;
typedef vector<int> ivec;
typedef vector<string> svec;

const int MOD=1000000007;
LL INF=1000000000000;

LL dp[1010][4100];
LL a[1010],c[1010];
int main(){
	LL n,m;cin>>n>>m;
	for(LL i=0;i<m;i++)
	{
		cin>>a[i];
		LL b;cin>>b;
		for(LL j=0;j<b;j++)
		{
			LL po;cin>>po;po--;
			c[i]+=(1 << po);	
		}	
	}
	
	for(LL i=0;i<1010;i++)
	{
		for(LL j=0;j<4100;j++)
		{
			if(j==0)dp[i][j]=0;
			else dp[i][j]=INF;
		}
	}
	
	for(LL i=0;i<m;i++)
	{
		for(LL j=0;j<(1 << n);j++)
		{
			LL nj=j|c[i];
			dp[i+1][j]=min(dp[i][j],dp[i+1][j]);
			dp[i+1][nj]=min(dp[i][j]+a[i],dp[i+1][nj]);	
		}
	}
	LL ans=dp[m][(1 << n)-1];
	if(ans==INF)cout<<-1<<"\n";
	else cout<<ans<<"\n";
	return 0;
}