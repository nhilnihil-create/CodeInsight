#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define int long long int
#define all(x) (x).begin(), (x).end()
#define present(c,x) (c.find(x) != c.end())
#define removeDuplicates(a) a.resize(unique(all(a))-a.begin())
#define endl '\n'

const int INF=1e9+5;

void solve(){
	int h,w;
	cin>>h>>w;
	vector<string>grid(h);
	for(int i=0;i<h;i++){
		cin>>grid[i];
	}
	vector<vector<int>>dp(h,vector<int>(w,INF));
	dp[0][0]=(grid[0][0]=='#');
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(i!=0){
				dp[i][j]=min(dp[i][j],dp[i-1][j]+(grid[i][j]=='#'&&grid[i-1][j]=='.'));
			}
			if(j!=0){
				dp[i][j]=min(dp[i][j],dp[i][j-1]+(grid[i][j]=='#'&&grid[i][j-1]=='.'));
			}
		}
	}
	int ans=dp[h-1][w-1];
	cout<<ans<<endl;
}

int32_t main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	solve();
}