#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll h,w;
  cin >> h >> w;

  vector<vector<char>> e(h+2,vector<char>(w+2,'a'));

  for(int i=0;i<w+2;i++){
    e[0][i]='#';
    e[h+1][i]='#';
  }

  for(int i=1;i<h+1;i++){
    e[i][0]='#';
    for(int j=1;j<w+1;j++)cin >> e[i][j];
    e[i][w+1]='#';
  }

  ll dp1[h+2][w+2];//縦方向
  ll dp2[h+2][w+2];
  memset(dp1,-1,sizeof(dp1));
  memset(dp2,-1,sizeof(dp2));

  for(int i=1;i<h+1;i++){
    for(int j=1;j<w+1;j++){
      if(dp1[i][j]!=-1)continue;
      if(e[i][j]=='#'){
        dp1[i][j]=0;
        continue;
      }
      ll k=0;
      while(e[i][j+k]=='.'){
        k++;
      }
      for(int l=0;l<k;l++){
        dp1[i][j+l]=k;
      }
    }
  }

  for(int i=1;i<h+1;i++){
    for(int j=1;j<w+1;j++){
      if(dp2[i][j]!=-1)continue;
      if(e[i][j]=='#'){
        dp2[i][j]=0;
        continue;
      }
      ll k=0;
      while(e[i+k][j]=='.'){
        k++;
      }
      for(int l=0;l<k;l++){
        dp2[i+l][j]=k;
      }
    }
  }

  ll m=0;
  for(int i=0;i<h+2;i++){
    for(int j=0;j<w+2;j++)m=max(m,dp1[i][j]+dp2[i][j]-1);
  }
  cout << m << endl;


}