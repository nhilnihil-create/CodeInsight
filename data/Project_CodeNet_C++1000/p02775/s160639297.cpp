#include <bits/stdc++.h>
#define INF 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

string s;
ll dp[1000005][2][12];

int main(void){
	cin >> s;
	s='0'+s;
	int n=s.size();
	for(int i=0;i<=n+1;i++){
		for(int j=0;j<2;j++){
			dp[i][0][j]=INF;
			dp[i][1][j]=INF;
		}
	}
	dp[0][0][0]=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				if(dp[i][j][k]==INF)continue;
				//printf("%d %d %d %lld\n",i,j,k,dp[i][j][k]);
				int p=(s[i]-'0');
				for(int l=0;l<=9;l++){
					int hav=k*10+l;
					if(hav<p)continue;
					if(hav==p){
						dp[i+1][j][0]=min(dp[i+1][j][0],dp[i][j][k]+l);
					}else{
						dp[i+1][j][1]=min(dp[i+1][j][1],dp[i][j][k]+l+hav-p-1);
						dp[i+1][j][0]=min(dp[i+1][j][0],dp[i][j][k]+l+hav-p);
					}
				}
			}
		}
	}
	ll ans=dp[n][0][0];
	printf("%lld\n",ans);
	return 0;
}
