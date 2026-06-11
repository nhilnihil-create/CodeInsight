#include<bits/stdc++.h>
using namespace std;
#define ff          first
#define ss          second
#define ll         	long long int
#define pb          push_back
#define ar 			array
#define mp 			make_pair
#define f(i,n)   	for(ll i =0;i<n;i++)
#define inf 		INT_MAX
#define pll 		pair<ll, pair<ll,ll>>
const ll INF = 1e18;
void init(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE 
		freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#endif
}
ll mod = 998244353;
void solve(){
	
	ll N,S;
	cin>>N>>S;
	vector<ll> A(N);
	for(ll i = 0;i<N;i++){
		cin>>A[i];
	}

	vector<vector<ll>> dp(N+1,vector<ll>(S+1 , 0));
	dp[0][0] = 1;
	for(ll i = 0;i<N;i++){

		for(ll j = 0; j<=S;j++){
			dp[i+1][j] += 2*dp[i][j];
			dp[i+1][j] %= mod;

			if(j + A[i] <= S){
				dp[i+1][j+A[i]] += dp[i][j];
				dp[i+1][j+A[i]] %= mod;
			}
		}
	}
	cout<<dp[N][S]<<endl;

}
int main(){
	init();
	ll t = 1;
	//cin>>t;
	for(ll i=1;i<=t;i++){
		//cout<<"Case #"<<i<<": ";
		solve();
	}
}
