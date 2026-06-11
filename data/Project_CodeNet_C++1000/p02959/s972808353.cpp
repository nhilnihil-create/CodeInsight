#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<long long>A(N+1);
  vector<long long>B(N);
  for(int X=0;X<N+1;X++){
    cin>>A[X];
  }
  for(int X=0;X<N;X++){
    cin>>B[X];
  }
  long long K=0;
  for(int X=0;X<N;X++){
    if(B[X]<=A[X]){
      K+=B[X];
      A[X]-=B[X];
    }
    else if(B[X]>=A[X]+A[X+1]){
      K+=A[X]+A[X+1];
      A[X]=0;
      A[X+1]=0;
    }
    else{
      K+=B[X];
      A[X+1]+=A[X]-B[X];
      A[X]=0;
    }
  }
  cout<<K<<endl;
}