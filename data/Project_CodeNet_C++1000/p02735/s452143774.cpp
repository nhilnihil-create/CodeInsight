#include<bits/stdc++.h>
using namespace std;
int H,W,dp[109][109],INF=1<<30;
char c[109][109];
int main(){
	cin>>H>>W;
	for(int i=1;i<=H;i++)for(int j=1;j<=W;j++)cin>>c[i][j];
	for(int i=1;i<=H;i++){
		for(int j=1;j<=W;j++){
			if(i==1&&j==1)dp[i][j]=0;
			else{
				dp[i][j]=INF;
				int score1=INF,score2=INF;
				if(i>=2){
					score1=dp[i-1][j];
					if(c[i-1][j]=='#'&&c[i][j]=='.')score1+=1;
				}
				if(j>=2){
					score2=dp[i][j-1];
					if(c[i][j-1]=='#'&&c[i][j]=='.')score2+=1;
				}
				dp[i][j]=min(score1,score2);
			}
		}
	}
	cout<<dp[H][W]+(c[H][W]=='#')<<endl;
	return 0;
}
