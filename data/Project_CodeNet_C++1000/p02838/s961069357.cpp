#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
  int N;
  cin>>N;
  long long A[300000][61];
  int S[300000][61];
  for(int i=0;i<N;i++){
    cin>>A[i][0];
    long long k=1;
    for(int j=1;j<=60;j++){
      A[i][j]=(A[i][0]%(k*2))/k;
      S[i][j]=A[i][j];
      k*=2;
    }
  }
  for(int i=N-2;i>=1;i--){
    for(int j=1;j<=60;j++) S[i][j]+=S[i+1][j];
  }
  long long answer=0;
  for(int i=0;i<N-1;i++){
    long long k=1;
    for(int j=1;j<=60;j++){
      if(A[i][j]==1) answer+=(N-1-i-S[i+1][j])*(k%1000000007);
      else answer+=S[i+1][j]*(k%1000000007);
      answer%=1000000007;
      k*=2;
    }
  }
  cout<<answer<<endl;
  
  return 0;
}