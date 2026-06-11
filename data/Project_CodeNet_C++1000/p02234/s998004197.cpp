#include <bits/stdc++.h>
#define N 110
using namespace std;
int A[N];
int dp[N][N];

int Min(int &a,int b){return a = min(a,b);}
int main(){
  int n;
  cin>>n;

  for(int i=0,cnt=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    if(i == 0) A[cnt++] = a;
    A[cnt++] = b;
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)dp[i][j] = 1e9;
    dp[i][i] = 0;
  }
  
  for(int len=0;len<n;len++)
    for(int l=1;l<n;l++){
      int r = l+len;
      if(l+len>=N)continue;
      for(int m = l;m<r;m++){
        Min(dp[l][r],dp[l][m] + dp[m+1][r] + A[l-1]*A[m]*A[r]);
      }
}
  
  cout<<dp[1][n]<<endl; 
  return 0;
}