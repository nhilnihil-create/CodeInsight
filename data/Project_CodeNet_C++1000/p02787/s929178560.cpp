#include <bits/stdc++.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> llP;

ll mod(ll a, ll b){
  ll ret=a%b;
  if(ret<0) ret+=b;
  return ret;
}

ll modpow(ll a,ll b,ll c){
  ll res=1;
  while(b>0){
    if(b&1) res=mod(res*a,c);
    a=mod(a*a,c);
    b>>=1;
  }
  return res;
}

int GCD(int x,int y){
  if(x<y){
    swap(x,y);
  }
  while(x%y!=0){
    int temp=x;
    x=y;
    y=temp%y;
  }
  return y;
}

int digitsum(int x){
  int sum=0;
  while(x>0){
    sum+=(x%10);
    x/=10;
  }
  return sum;
}

int dp[1001][20010];

int main() {
  int h,n;
  cin>>h>>n;
  int a[n+1],b[n+1];
  for(int i=1;i<=n;i++){
    cin>>a[i]>>b[i];
  }
  for(int i=0;i<20010;i++){
    dp[0][i]=1e9;
  }
  dp[0][0]=0;
  for(int i=1;i<=n;i++){
    for(int j=0;j<20010;j++){
      dp[i][j]=dp[i-1][j];
      if(j-a[i]>=0){
        dp[i][j]=min(dp[i][j],dp[i][j-a[i]]+b[i]);
      }
    }
  }
  int ans=dp[n][h];
  for(int i=h+1;i<20010;i++){
    ans=min(ans,dp[n][i]);
  }
  cout<<ans<<endl;
  return 0;
}
