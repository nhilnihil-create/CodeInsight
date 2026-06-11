#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  int sum=0;
  vector<int> A(N),B(N),C(N-1);
  for(int i=0; i<N; i++){
    cin>>A.at(i);
  }
  for(int i=0; i<N; i++){
    cin>>B.at(i);
    sum+=B.at(i);
  }
  for(int i=0; i<(N-1); i++){
    cin>>C.at(i);
  }
  int a;
  
  for(int i=0; i<(N-1); i++){
    if((A.at(i)+1)==A.at(i+1)){
      if(A.at(i)!=N){
        sum+=C.at(A.at(i)-1);
      }
    }
  }
  cout<<sum<<endl;
}