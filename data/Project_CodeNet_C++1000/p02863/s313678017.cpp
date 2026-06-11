#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int DP1[3005][3005];
int DP2[3005][3005];

int main() {
  int N, T;
  cin>>N>>T;
  int A[N], B[N];
  for(int i=0;i<N;++i) cin>>A[i]>>B[i];
  for(int j=0;j<T;++j){
    if(A[0]<=j) DP1[0][j] = B[0];
  }
  for(int i=1;i<N;++i){
    for(int j=0;j<T;++j){
      if(A[i]>j) DP1[i][j] = DP1[i-1][j];
      else DP1[i][j] = max(DP1[i-1][j], DP1[i-1][j-A[i]]+B[i]);
    }
  }
  for(int j=0;j<T;++j){
    if(A[N-1]<=j) DP2[N-1][j] = B[N-1];
  }
  for(int i=N-2;i>=0;--i){
    for(int j=0;j<T;++j){
      if(A[i]>j) DP2[i][j] = DP2[i+1][j];
      else DP2[i][j] = max(DP2[i+1][j], DP2[i+1][j-A[i]]+B[i]);
    }
  }
  int ans = 0;
  for(int i=0;i<N;++i){
    if(i==0) {
      ans = max(ans, DP2[i+1][T-1]+B[0]);
    }
    else if(i==N-1) {
      ans = max(ans, DP1[N-2][T-1]+B[N-1]);
    }
    else {
      for(int j=0;j<T;++j){
        ans = max(ans, DP1[i-1][j]+DP2[i+1][T-1-j]+B[i]);
      }
    }
  }
  cout<<ans<<endl;
}
