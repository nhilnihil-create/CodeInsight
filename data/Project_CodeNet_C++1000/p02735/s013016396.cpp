#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
#include<math.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
int  main(){
  ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	cout.tie(0);
    ll h,w,i,j,k;
    cin>>h>>w;
    char s[h][w];
    ll dp[h][w];


    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
        cin>>s[i][j];
        dp[i][j]=INT_MAX;
    }
  }
    ll x,y;
    ll a[2]={1,0};
    ll b[2]={0,1};
    //dp[0][0]=(s[0][0]=='.')?0:1;

    if(s[0][0]=='.') dp[0][0]=0;
    else dp[0][0]=1;

    for(i=0;i<h;i++){
      for(j=0;j<w;j++){
        for(k=0;k<2;k++){
          x=i+a[k];
          y=j+b[k];
          int sum=0;
          if(x>=h||y>=w)
            continue;
          if(s[i][j]=='.'&&s[x][y]=='#')
            sum=1;
          dp[x][y]=min(dp[i][j]+sum,dp[x][y]);
        }
      }
    }
    cout<<dp[h-1][w-1]<<endl;
  }
