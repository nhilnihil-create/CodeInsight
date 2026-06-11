#include<bits/stdc++.h>
using namespace std;

int main(){
  long A,B,C,K,sum=0;
  cin>>A>>B>>C>>K;
  
  if(K-A>=0){
    sum=1*A;
    if(K-A-B>0){
      sum+=(-1)*(K-A-B);
    }
  }
  else{
    sum=1*K;
  }
  cout<<sum<<endl;
}
