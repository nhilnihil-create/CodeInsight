#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N=100,INF=(1<<30)-1;

int n,m;
char s[N+9][N+9];

void into(){
  scanf("%d%d",&n,&m);
  for (int i=1;i<=n;++i)
	scanf("%s",s[i]+1);
}

int dp[N+9][N+9];

void Get_dp(){
  dp[1][1]=s[1][1]=='#';
  for (int i=1;i<=n;++i)
	for (int j=1;j<=m;++j){
	  if (i==1&&j==1) continue;
	  dp[i][j]=INF;
	  if (i>1) dp[i][j]=min(dp[i][j],dp[i-1][j]+(s[i-1][j]=='.'&&s[i][j]=='#'));
	  if (j>1) dp[i][j]=min(dp[i][j],dp[i][j-1]+(s[i][j-1]=='.'&&s[i][j]=='#'));
	}
}

void work(){
  Get_dp();
}

void outo(){
  printf("%d\n",dp[n][m]);
}

int main(){
  into();
  work();
  outo();
  return 0;
}