/*********************
*  Author: xuziyuan  * 
*********************/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
#define sqr(a) ((a)*(a))

using namespace std;

const LL MOD=1e9+7;

int n,ans[510][510];

void solve(int lb,int ub,int co)
{
	int mid=(lb+ub)/2;
	for(int i=lb;i<=mid;i++) for(int j=mid+1;j<=ub;j++) ans[i][j]=co;
	if(lb==ub) return;
	solve(lb,mid,co+1);
	solve(mid+1,ub,co+1);
}

int main()
{
	cin>>n;
	solve(1,n,1);
	repn(i,n-1)
	{
		for(int j=i+1;j<=n;j++) cout<<ans[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}