#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)n; ++i)
using namespace std;
using ll = long long;

int main(){
  int N;
  cin>>N;
  vector<int>A(N+1),B(N);
  for(int i=0;i<N+1;i++){
    cin>>A[i];
  }
  for(int i=0;i<N;i++){
    cin>>B[i];
  }
  int64_t sum=0;
  for(int i=0;i<N;i++){
    if(A[i]<=B[i]){
      sum+=A[i];
      int sp=B[i]-A[i];
      A[i]=0;
      if(A[i+1]<=sp){
        sum+=A[i+1];
        A[i+1]=0;
      }
      else{
        A[i+1]-=sp;
        sum+=sp;
      }
    }
    else{
      sum+=B[i];
      A[i]-=B[i];
    }
  }
  cout<<sum<<endl;
  return 0;
}