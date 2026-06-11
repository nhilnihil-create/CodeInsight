#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;vector<int>A(N),B(N);
  for(int X=0;X<N;X++){
    cin>>A[X];B[X]=A[X];
  }
  sort(B.begin(),B.end());
  int H=0;
  for(int X=0;X<N;X++){
    if(A[X]!=B[X]){
      H++;
    }
  }
  if(H==2||H==0)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}