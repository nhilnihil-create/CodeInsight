#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,sum=0;
  cin>>N;
  vector<int> A(N),B(N);
  vector<int> C(N-1);
  for(int i=0; i<N; i++){
    cin>>A.at(i);
  }
  for(int i=0; i<N; i++){
    cin>>B.at(i);
    sum+=B.at(i);
  }
  for(int i=0; i<N-1; i++){
    cin>>C.at(i);
  }
  for(int i=0; i<N-1; i++){
    for(int j=0; j<N-1; j++){
      if(A.at(i)==j+1&&A.at(i+1)==j+2){
        sum+=C.at(j);
      }
    }
  }
  cout<<sum<<endl;
}
  