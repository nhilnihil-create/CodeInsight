#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;
int main(){
  int N;
  cin>>N;
  long long A[200000],B[200000];
  for(int i=0;i<N;i++){
    cin>>A[i]>>B[i];
  }
  sort(A,A+N);
  sort(B,B+N);
  long long meda,medb;
  if(N%2==0){
    meda=A[N/2-1]+A[N/2];
    medb=B[N/2-1]+B[N/2];
  }
  else{
    meda=A[N/2];
    medb=B[N/2];
  }
  cout<<medb-meda+1<<endl;
  
  return 0;
}