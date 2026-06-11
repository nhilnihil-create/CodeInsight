#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
#define fr(i,k,n) for (int i = k; i < n; ++i)
#define fri(i,k,n) for (int i = k; i >= n; --i)
#define INF (int)1e9
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define all(arr) arr.begin(),arr.end()

void boost(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int N=1e6+5;
ll dp[4][N];

void solve(){
	int n;
	cin>>n;
	dp[0][0]=1;
	fr(i,1,n+1){
		dp[0][i]=(dp[0][i-1]*8LL)%MOD;
		dp[1][i]=(dp[0][i-1] + dp[1][i-1]*9LL)%MOD;
		dp[2][i]=(dp[0][i-1] + dp[2][i-1]*9LL)%MOD;
		dp[3][i]=(dp[1][i-1] + dp[2][i-1] + dp[3][i-1]*10LL)%MOD;
	}
	cout<<dp[3][n]<<endl;
	return;
}

int main()
{
	boost();
	
	int tc=1;
	//cin>>tc;
	while(tc--)
		solve();
	return 0;
}