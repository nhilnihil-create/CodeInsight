#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 500010
using namespace std;
ll n,k,c,dp[N];
string s;
vector<ll> mst;
int main(){
	ll i;
	cin>>n>>k>>c>>s;
	for(i=0;i<n;i++)
	{
		if(s[i]=='o')
		{
			mst.push_back(i);
			i+=c;
		}
	}
	if(mst.size()>k)
	{
		return 0;
	}
	for(i=n;i>=0;i--)
	{
		if(s[i]=='o')
		{
			dp[i]=max(dp[i+1],dp[i+c+1]+1);
		}
		else
		{
			dp[i]=dp[i+1];
		}
	}
	for(i=0;i<mst.size();i++)
	{
		if(i+dp[mst[i]+1]==k-1)
		{
			cout<<mst[i]+1<<endl;
		}
	}
	return 0;
}