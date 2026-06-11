#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#include<cmath>
#define INF 2147483647
#define IN 2047483647
#define llINF 9223372036854775807
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long

using namespace std;
int main(){
  int a,b;
  while(cin>>a>>b,a+b){
    int n;
    cin>>n;
    ll dp[2*a][2*b]={};
    int MAP[2*a][2*b]={};
    for(int i=0;i<n;i++){
      int x,y;
      cin>>x>>y;
      MAP[x][y]=1;
    }
    for(int i=1;i<=a;i++){
      if(MAP[i][1])
	break;
      dp[i][1]=1;
    }
    for(int i=1;i<=b;i++){
      if(MAP[1][i])
	break;
      dp[1][i]=1;
    }
    for(int i=2;i<=a;i++){
      for(int j=2;j<=b;j++){
	if(MAP[i][j])
	  continue;
	dp[i][j]=dp[i][j-1]+dp[i-1][j];
      }
    }
    cout<<dp[a][b]<<endl;
  }
  return 0;
}