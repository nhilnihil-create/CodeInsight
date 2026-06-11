#include "bits/stdc++.h"
using namespace std;

const int N=2e3+20;

int n,x;
vector <pair <int,int>> v;
long long dp[N][N];

long long f(int l,int r)
{
	long long &ans=dp[l][r];
	if(ans!=-1) return ans;

	int i=l+(n-1-r); // total i elements have been assigned position
	int old_pos=v[i].second;
	if(l==r) return ans=v[i].first*abs(l-old_pos); // only 1 position possible which is l
	//else we can put it on two ends l or r
	return ans=max(1ll*v[i].first*abs(l-old_pos)+f(l+1,r), 1ll*v[i].first*abs(r-old_pos)+f(l,r-1));
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		v.push_back({x,i});
	}

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) dp[i][j]=-1;
	sort(v.rbegin(),v.rend());
	printf("%lld",f(0,n-1));
}