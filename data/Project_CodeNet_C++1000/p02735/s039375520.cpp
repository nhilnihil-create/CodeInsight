#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

const int INF=0x3f3f3f3f;

int dp[200][200][2];
char s[200][200];

int main(){
	int h,w;cin>>h>>w;
	rep(i,h)scanf("%s",s[i]);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][s[0][0]=='.'?0:1]=(s[0][0]=='#');
	rep(i,h)rep(j,w)rep(k,2){
		if(dp[i][j][k]==INF)continue;
		if(i+1<h){
			int t=(s[i+1][j]=='.'?0:1);
			dp[i+1][j][t]=min(dp[i+1][j][t],dp[i][j][k]+(k==0&&t==1));
		}
		if(j+1<w){
			int t=(s[i][j+1]=='.'?0:1);
			dp[i][j+1][t]=min(dp[i][j+1][t],dp[i][j][k]+(k==0&&t==1));
		}
	}
	cout<<min(dp[h-1][w-1][0],dp[h-1][w-1][1])<<endl;
}