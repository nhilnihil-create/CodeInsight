#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
typedef pair<int,int>pii;
typedef long long ll;
const int N = 2000;
ll dp[N+10][N+10];
pii a[N+10];

ll solve(int l,int r,int pos)
{
	//printf("%d %d %d\n",l,r,pos);
	if(r-l==1){
		return 0;
	}
	if(dp[l][r]!=0){
		return dp[l][r];
	}
	ll t1 = 1ll*a[pos].first*(abs(l+1-a[pos].second));
	ll t2 = 1ll*a[pos].first*(abs(r-1-a[pos].second));
	ll mx = 0;
	mx = max(mx,t1+solve(l+1,r,pos+1));
	mx = max(mx,t2+solve(l,r-1,pos+1));
	return dp[l][r] = mx;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].first);;
		a[i].second = i;
	}
	sort(a+1,a+n+1,greater<pii>());
	printf("%lld\n",solve(0,n+1,1));
}
