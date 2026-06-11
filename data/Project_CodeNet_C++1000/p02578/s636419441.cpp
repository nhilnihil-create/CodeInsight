#include"bits/stdc++.h"
using namespace std;
int main() {
  int64_t N,ans=0;
  cin>>N;
  vector<int> A(N);
  vector<int> B(N-1);
  for(int i =0;i<N;i++){
    cin>>A[i];
  }
  for(int k =1;k<N;k++){
    if(A[k]<A[k-1]){
      B[k-1]=A[k-1]-A[k];
      A[k]=A[k-1];
      ans+=B[k-1];
    }
  }
  cout<<ans<<endl;
}
