#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define all(a) a.begin(),a.end()
#define dbg(n) cout<<#n<<' '<<n<<endl;
#define dbg_v(v) cout<<#v<<":";for(auto c:v) cout<<" "<<c; cout<<endl;
int power(ll x,ll y){ll res = 1;while(y>0){if(y&1)res = (res*x)%mod;y=y>>1;x=(x*x)%mod;}return res;}
void solve(){
	ll h,n;
	cin>>h>>n;
	int dp[n][h+1];
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<n;i++)
		dp[i][0]=0;
	for(int i=1;i<=h;i++){
		dp[0][i]=(i-a[0]>=0)?dp[0][i-a[0]]+b[0]:b[0];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=h;j++){
			if(j-a[i]>=0)
				dp[i][j]=min(dp[i-1][j],dp[i][j-a[i]]+b[i]);
			else
				dp[i][j]=min(dp[i-1][j],b[i]);
		}
	}
	cout<<dp[n-1][h]<<endl;
}
int main(){ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
}
