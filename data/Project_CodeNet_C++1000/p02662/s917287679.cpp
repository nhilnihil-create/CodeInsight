#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define endl "\n"
#define pii pair<int,int> 
#define ff first
#define ss second
#define mii map<int,int>
#define si set<int>
#define sti stack<int>
#define qi queue<int>
#define vi vector<int>
#define pq priority_queue<int>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int M=998244353;

void self_add(int &x,int &y){
	x=(x+y)%M;
}

void solve(){
	int n,s;
	cin>>n>>s;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int dp[n+1][s+1];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=s;j++){
			dp[i+1][j]=(dp[i+1][j]+2*dp[i][j])%M;
			if(j+a[i]<=s){
				self_add(dp[i+1][j+a[i]],dp[i][j]);
			}
		}
	}
	cout<<dp[n][s]<<endl;
}

int32_t main(){
	IOS;
	int t=1;
	//cin>>t;
	while(t--){
		solve();	
	}
}