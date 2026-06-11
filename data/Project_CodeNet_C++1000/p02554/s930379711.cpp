#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define REP(i,j) for(int i=0;i<j;i++)
#define FORN(i,j,k) for(int i=j;i<k;i++)
#define vi vector<int>
#define vvi vector<vi >
#define pii pair<int,int>
#define vpii vector<pii >
#define all(a) a.begin(),a.end()
using namespace std;
ll MOD=1e9+7;
int n;
ll dp[1000005][2][2];

int main(void){
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	dp[0][0][0]=8ll;
	dp[0][1][0]=1ll;
	dp[0][0][1]=1ll;
	dp[0][1][1]=0ll;
	FORN(i,1,n){
		dp[i][0][0]=(dp[i-1][0][0]*8ll)%MOD;
		dp[i][1][0]=(dp[i-1][0][0]+(dp[i-1][1][0]*9ll)%MOD)%MOD;
		dp[i][0][1]=(dp[i-1][0][0]+(dp[i-1][0][1]*9ll)%MOD)%MOD;
		dp[i][1][1]=((dp[i-1][0][1]+dp[i-1][1][0])%MOD+(dp[i-1][1][1]*10ll)%MOD)%MOD;
	}
	cout<<dp[n-1][1][1]%MOD;
	return 0;
}