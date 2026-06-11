#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int N;
  cin>>N;
  
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  
  vector<int> B(N);
  for(int i=0;i<N;i++){
    cin>>B[i];
  }
  
  vector<int> C(N);
  for(int i=0;i<N-1;i++){
    cin>>C[i];
  }
  
  
  int ans=0;
  
  for(int i=0;i<N;i++){
    ans+=B[i];
  }
  
  for(int j=0;j<N-1;j++){
    if(A[j+1]==A[j]+1){
      ans+=C[A[j]-1];
    }
  }
  
  
  cout<<ans<<endl;
}