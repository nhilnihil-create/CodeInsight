// Winners don't quit and Quitters don't win
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define mod 998244353
#define MAX 100005
ll dp[2003][2003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,i,ans=0,x,l,r,j;
    pll a[2005];
    cin>>n;
    for(i=1;i<=n;++i){
    	cin>>a[i].first;
    	a[i].second=i;
	}
	sort(a+1,a+1+n,greater<pll>());
	for(i=1;i<n+1;++i){
		for(j=0;j<i;++j){
			l=j;
			r=i-1-j;
			dp[l+1][r]=max(dp[l+1][r],dp[l][r]+abs(l+1-a[i].second)*a[i].first);
			r=j;
			l=i-1-j;
			dp[l][r+1]=max(dp[l][r+1],dp[l][r]+abs(n-r-a[i].second)*a[i].first);
		}
	}
	for(i=0;i<n;++i){
		ans=max(ans,dp[i][n-i]);
	}
	cout<<ans;
}