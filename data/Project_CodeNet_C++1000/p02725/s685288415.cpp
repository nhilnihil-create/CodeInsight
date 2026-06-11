#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int K,N;
  cin>>K>>N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A[i];
  }
  sort(A.begin(),A.end());
  int ma=0;
  for(int i=1;i<N;i++){
    int d=0;
    d=A[i]-A[i-1];
    if(d>ma){
      ma=d;
    }
  }
  if(A[0]+K-A[N-1]>ma){
    ma=A[0]+K-A[N-1];
  }
  cout<<K-ma<<endl;
}