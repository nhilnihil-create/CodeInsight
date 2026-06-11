#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main() {

  int N,M;
  cin>>N>>M;
  
  if(N==1 && M>1){
    cout<<M*(M-1)/2<<endl;
  }
  else if(N>1 && M==1){
    cout<<N*(N-1)/2<<endl;
  }
  else if(N==1 && M==1){
    cout<<0<<endl;
  }
  else{
    cout<<M*(M-1)/2+N*(N-1)/2<<endl;
  }
}
    
    