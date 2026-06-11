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

vector<vll> dp(2002,vll(2002,0));

void solve(){
	int s;
	cin>>s;
	fr(i,3,s+1){
		dp[i][1]=1;
	}
	vll sum(2002,0);
	fr(i,6,s+1){
		fr(j,1,2002){
			sum[j]=(sum[j]+dp[i-3][j])%MOD;;
			dp[i][j]=(dp[i][j]+sum[j-1])%MOD;
		}
	}
	ll total=0;
	fr(i,0,2002){
		total=(total+ dp[s][i])%MOD;
	}
	cout<<total<<endl;
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