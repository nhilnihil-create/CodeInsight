#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int maxn=2e3+5;
typedef long long ll;
ll dp[maxn][maxn];
int n;
pair<int,int> a[maxn];
inline bool cmp1(pair<int,int> a1,pair<int,int> b1){
	return a1.first>b1.first;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i].first);
		a[i].second=i;
	}
	sort(a+1,a+n+1,cmp1);
	memset(dp,0xf3,sizeof(dp));
	dp[0][0]=0;
	ll ans=-1e14;
	for (int len=1;len<=n;len++){
		for (int l=0;l<=len;l++){
			int r=len-l;
			int ot=n-r+1;
			if (l) dp[l][r]=max(dp[l][r],dp[l-1][r]+1ll*(a[len].second-l)*a[len].first);
			if (r) dp[l][r]=max(dp[l][r],dp[l][r-1]+1ll*(ot-a[len].second)*a[len].first);
			if (len==n) ans=max(ans,dp[l][r]);
		}
	}
	cout<<ans<<endl;
}