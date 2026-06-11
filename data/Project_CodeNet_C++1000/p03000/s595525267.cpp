#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,X,j=1,k=0;
  cin>>N>>X;
  for(int i=0;i<N;i++){
    int L;
    cin>>L;
    k+=L;
    if(k<=X)
      j++;
  }
  cout<<j<<endl;
}