#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N=2001;

struct kid{
	int val;
	int pos;
	bool operator<(const kid &a) const{
		return val>a.val;
	}
};

kid a[N];
int dp[N][N];

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].val;
		a[i].pos=i;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int l=0;l<=i;l++){
			int r=n-(i-l)-1;
			dp[i+1][l+1]=max(dp[i+1][l+1],dp[i][l]+a[i].val*abs(l-a[i].pos));
			dp[i+1][l]=max(dp[i+1][l],dp[i][l]+a[i].val*abs(r-a[i].pos));
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)
		ans=max(ans,dp[n][i]);
	cout<<ans<<"\n";
}