#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2005;
const int M = 2005;
const int mod = 1e9 + 7;

int n, m;
int A[N], B[M], R[M];
int dp[N][M];

signed main(){
  
  cin>>n>>m;
  
  for(int i=0;i<n;i++) cin>>A[i];
  
  for(int i=0;i<m;i++) cin>>B[i];
  
  for(int i=0;i<n;i++){
    
    int sum = 0;
    
    for(int j=0;j<m;j++){
      
      if( A[i] == B[j] ){
	dp[i][j] = sum + 1;
	dp[i][j] %= mod;
      }
      
      sum += R[j];
      sum %= mod;
      
    }
    
    for(int j=0;j<m;j++){
      
      if( A[i] == B[j] ){
	R[j] += dp[i][j];
	R[j] %= mod;
      }
      
    }
    
  }
  
  int sum = 0;

  for(int i=0;i<m;i++){
    sum += R[i];
    sum %= mod;
  }
  
  int ans = ( sum + 1 ) % mod;
  
  cout<<ans<<endl;
  
  return 0;
}
