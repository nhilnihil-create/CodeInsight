
#include <iostream>
using namespace std;

#define int long long
#define f(i,n) for(int i=0;i<n;i++)
#define pll pair<long,long>
#define S second
#define F first

signed main(){
	int n;
	cin>>n;
	pll a[n+1];
	int dp[n+1][n+1];
	f(i,n+1) f(j,n+1) dp[i][j]=0;

	for(int i=1;i<n+1;i++){
		cin>>a[i].F; //so  that it can be compared for descending
		a[i].S=i;
	}

	sort(a+1,a+n+1,greater<pll>());

	for(int i=1;i<n+1;i++){
		//currently at ith index of our sorted weights
		//i-1 weights have already been placed
		for(int j=0;j<i;j++){
			int L = j;
			int R = i-1-j;
			dp[L+1][R] = max(
				dp[L+1][R],
				dp[L][R] + abs(L+1 - a[i].S)*a[i].F
			);
			dp[L][R+1] = max(
				dp[L][R+1],
				dp[L][R] + abs(n-R - a[i].S)*a[i].F
			);
		}
	}

	int ans=0;
	for(int i=0;i<n+1;i++){
		//num ele to left
		ans = max(ans,dp[i][n-i]);
	}
	cout<<ans<<endl;
	return 0;
}
