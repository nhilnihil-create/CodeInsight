#pragma GCC optimize("-Ofast","-funroll-all-loops")
#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x &(-x))
#define endl '\n'
using namespace std;
const int INF=0x3f3f3f3f;
const int dir[4][2]={-1,0,1,0,0,-1,0,1};
const double PI=acos(-1.0);
const double e=exp(1.0);
const double eps=1e-10;
const int M=1e9+7;
const int N=2e5+10;
typedef long long ll;
typedef pair<int,int> PII;
typedef unsigned long long ull;
int mp[110][110],dp[110][110];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int h,w;
	cin>>h>>w;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			char c;
			cin>>c;
			c=='#'?mp[i][j]=1:mp[i][j]=0;
		}
	}
	dp[0][0]=mp[0][0];
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(i+j==0) continue;
			dp[i][j]=INF;
			if(i>0) dp[i][j]=min(dp[i][j],dp[i-1][j]+(mp[i][j]&&!mp[i-1][j]));
			if(j>0) dp[i][j]=min(dp[i][j],dp[i][j-1]+(mp[i][j]&&!mp[i][j-1]));
		}
	}
	cout<<dp[h-1][w-1]<<endl;
	return 0;
}
