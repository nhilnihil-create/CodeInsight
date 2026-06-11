#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define puts(i) cout<<i<<endl
#define pi 3.14159265358979323846264338
#define pb push_back
#define mp make_pair
#define inf 10000
using ll = long long;
using P = pair<int,int>;
using Pll = pair<ll,ll>;

ll divisor=1000000007;
int main(){
	int h,w;
	cin>>h>>w;
	char s[h][w];
	int dp[h][w]={};
	rep(i,h)rep(j,w)dp[i][j]=divisor;
	rep(i,h){
		rep(j,w){
			cin>>s[i][j];
		}
	}
	dp[0][0]=1;
	for(int i=1;i<h;i++){
		if(s[i-1][0]!=s[i][0])
			dp[i][0]=dp[i-1][0]+1;
		else
			dp[i][0]=dp[i-1][0];
	}
	for(int i=1;i<w;i++){
		if(s[0][i-1]!=s[0][i])
			dp[0][i]=dp[0][i-1]+1;
		else
			dp[0][i]=dp[0][i-1];
	}
	rep(i,h){
		rep(j,w){
			if(dp[i][j]!=divisor)continue;
			dp[i][j]=min(dp[i-1][j]+(s[i-1][j]!=s[i][j]),dp[i][j-1]+(s[i][j-1]!=s[i][j]));
		}
	}
  	/*rep(i,h){
		rep(j,w){
			cout<<dp[i][j];}
      	cout<<endl;
    }*/
      
	int ans=dp[h-1][w-1]/2;
	if(s[0][0]=='#'&&s[h-1][w-1]=='#')ans++;
	cout<<ans<<endl;
	
}
