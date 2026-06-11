#include<iostream>
#include<stdlib.h>
using namespace std;

int main () {
  int a,b;
  while(cin>>a>>b,a|b){
    int x,y,m=0;
    int d[a*b]={};int k;cin>>k;
    for(int i=0;i<k;++i){
      cin>>x>>y;x--;y--;
      d[x+y*a]=1;
    }
    int dp[2][a*b];
    for(int i=0;i<2;++i)for(int j=0;j<a*b;++j)dp[i][j]=0;
    dp[1-m][0]=1;
    while(true){
      for(y=0;y<b;++y){
	for(x=0;x<a;++x){
	  if(d[x+y*a])continue;
	  if(dp[m][x+y*a]==0){
	    if(x>=1){dp[m][x+y*a]+=dp[1-m][(x-1)+y*a];}
	    if(y>=1){dp[m][x+y*a]+=dp[1-m][x+(y-1)*a];}
	  }
	}
      }
      bool t = false;
      for(int i=0;i<a*b;++i){if(dp[1-m][i]!=dp[m][i])t=true;dp[1-m][i]=dp[m][i];}
      if(!t){cout<<dp[m][a*b-1]<<endl;break;}
      m=1-m;
    }
  }
}