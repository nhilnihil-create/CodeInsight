#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, S;
  cin >> N >> S;
  long int A[N];
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  
  long long int F[N+1][S+1];
  F[0][0]=1;
  for(int j=1;j<S+1;j++){
    F[0][j]=0;
  }
  
  for(int i=1;i<N+1;i++){
    for(int j=0;j<S+1;j++){
      if(j-A[i-1]<0){
        F[i][j]=F[i-1][j]*2;
      }else{
        F[i][j]=F[i-1][j]*2 + F[i-1][j-A[i-1]];
      }
      F[i][j] = F[i][j]%998244353;
    }
  }
    
  cout << F[N][S];
  return 0;
}
