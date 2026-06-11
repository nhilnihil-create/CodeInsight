#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
  int N;
  long long K;
  cin>>N>>K;
  int A[2000],B[2000],C[2000];
  for(int i=0;i<N;i++){
    cin>>A[i];
    B[i]=0;
    C[i]=0;
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(A[i]>A[j]){
        B[i]++;
        if(i<j) C[i]++;
      }
    }
  }
  long long answer=0;
  for(int i=0;i<N;i++){
    long long k=(((K-1)*K)/2)%1000000007;
    answer=(answer+B[i]*k+C[i]*K)%1000000007;
  }
  cout<<answer<<endl;
  
  return 0;
}