#include <bits/stdc++.h>
using namespace std;
#define fi first
#define endl "\n"
#define se second
#define ll long long
#define inf 0x3f3f3f3f
#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int N = 3e3+5;
const ll mod =   1e9+7;
int n,t;int a[N],b[N];int dp[N][7000];vector<pair<int,int> > vp;
int main()
{  fast
cin>>n>>t;
for(int i=0;i<n;i++)
{
	int x,y;
	cin>>x>>y;
	vp.emplace_back(x,y);
}
sort(vp.begin(),vp.end());
for(int i=0;i<n;i++){
	for(int j=7000;j>=0;j--){dp[i+1][j]=dp[i][j];
		if(j<t&&dp[i+1][j+vp[i].fi]<dp[i][j]+vp[i].se)
		dp[i+1][j+vp[i].fi]=dp[i][j]+vp[i].se;
	}
}
int ans=0;
for(int i=0;i<7000;i++)
ans=max(ans,dp[n][i]);
cout<<ans;
}
