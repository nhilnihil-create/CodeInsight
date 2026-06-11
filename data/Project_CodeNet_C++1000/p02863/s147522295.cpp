#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 6e3+69;
const int mod = 1e9+7;
int m,n;
int t;
int x,y,z;
struct vl{
	int x,y;
	bool operator<(vl t)const {
		if(x==t.x)return y<t.y;
		return x<t.x;
	}
};
int dp[MAXN];
vl a[MAXN];
signed main(){																																																																																						ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=MAXN-1;j>=0;j--){
			if(j>=a[i].x&&j-a[i].x<t){
				dp[j]=max(dp[j],dp[j-a[i].x]+a[i].y);
			}
			
			//cout<<dp[j]<<' ';
		}
		//cout<<endl;
	}
	int ans = 0;
	for(int i=0;i<MAXN;i++){
		//cout<<dp[i]<<' ';
		ans = max(ans,dp[i]);
	}
	cout<<ans;
}  
/*
3 5
5 7
3 4
4 4
*/