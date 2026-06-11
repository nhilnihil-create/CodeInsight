#include <iostream>
#include <algorithm>
using namespace std;
long long n;
pair <long long,long long> a[2005];
long long dp[2005][2005];//dp[i][j]表示前i大的数，有j个被放到了左边 
int main(int argc, char** argv) {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].first;
		a[i].first=-a[i].first;
		a[i].second=i;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) a[i].first=-a[i].first;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		//cout << a[i].first << " " << a[i].second << "\n";
		for(int j=0;j<i;j++)
		{
			long long l=j+1,r=n-(i-j-1);
			dp[i][j+1]=max(dp[i][j+1],dp[i-1][j]+(a[i].second-l)*a[i].first);
			dp[i][j]=max(dp[i][j],dp[i-1][j]+(r-a[i].second)*a[i].first);
			ans=max(ans,dp[i][j]);
		}
	}
	cout << ans;
	return 0;
}