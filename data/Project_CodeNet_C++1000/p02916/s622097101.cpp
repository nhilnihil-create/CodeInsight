#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  vector<int> A(N),B(N),C(N-1);
  for(int &i:A)
    cin>>i;
  for(int &i:B)
    cin>>i;
  for(int &i:C)
    cin>>i;
  int j=0,k=30;
  for(int i:A){
    j+=B[i-1];
    if(i==k+1){
      j+=C[i-2];
    }
    k=i;
  }
  cout<<j<<endl;
}
