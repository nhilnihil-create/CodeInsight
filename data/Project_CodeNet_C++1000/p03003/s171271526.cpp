#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int a[2005],b[2005],la,lb,mod=1e9+7;
int dp[2005][2005];
signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>la>>lb;
	dp[0][0]=1;
	FOR(i,1,la)cin>>a[i],dp[i][0]=1;
	FOR(i,1,lb)cin>>b[i],dp[0][i]=1;
	FOR(i,1,la){
		FOR(j,1,lb){
			dp[i][j]=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mod)%mod;
			if(a[i]==b[j])dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
		}
	}
	cout<<dp[la][lb];
	RE 0;
}


