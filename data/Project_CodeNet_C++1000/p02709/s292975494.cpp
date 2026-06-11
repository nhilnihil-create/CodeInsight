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
typedef pair<int,int> P;
typedef pair<LL,LL> PL;

const int MOD=1000000007;

vector<PL> v; 
LL dp[2020][2020];
int main()
{
	LL n,ans=0;
	cin>>n;
	for(LL i=0;i<n;i++)
	{
		LL x;cin>>x;
		v.push_back(PL(x,i));
	}
	sort(v.begin(),v.end(),greater<PL>());
	for(LL i=0;i<=n;i++)
	{
		for(LL j=0;j<=n-i;j++)
		{
			LL I=0,J=0;
			if(i>=1)I=dp[i-1][j]+v[i+j-1].first*abs(v[i+j-1].second-(i-1));
			if(j>=1)J=dp[i][j-1]+v[i+j-1].first*abs(v[i+j-1].second-(n-j));
			dp[i][j]=max(I,J);
			if(i+j==n)ans=max(ans,dp[i][j]);
			//cout<<dp[i][j]<<" ";
		}
		//cout<<"\n";
		
	}
	cout<<ans<<"\n";
	return 0;
}