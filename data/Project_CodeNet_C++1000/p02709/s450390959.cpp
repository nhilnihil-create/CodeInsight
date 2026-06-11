#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
#define INF 1000000000000000007ll
using namespace __gnu_pbds;
using namespace std;

int n,dp[2020][2010];
pair<int,int> a[2010];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first;
		a[i].second=i;
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[i][j]=-INF;
	dp[0][0]=0;
	int ans=-INF; 
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			int num1=j,num2=i-j;
			if(num1>0){
				int pos=num1;
				int cur=a[i].first*(a[i].second-pos);
				dp[num1][num2]=max(dp[num1][num2],dp[num1-1][num2]+cur);
			}
			if(num2>0){
				int pos=n-num2+1;
				int cur=a[i].first*(pos-a[i].second);
				dp[num1][num2]=max(dp[num1][num2],dp[num1][num2-1]+cur);
			}
			if(i==n) ans=max(ans,dp[num1][num2]);
		}
	}
	cout<<ans<<endl;
	return 0;
}