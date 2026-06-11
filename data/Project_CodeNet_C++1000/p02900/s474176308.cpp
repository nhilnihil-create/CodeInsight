#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t A,B;
  cin>>A>>B;
  while(A!=0&&B!=0){
    if(A>B){
      A=A%B;
    }
    else{
      B=B%A;
    }
  }
  int64_t Z=1,X=max(A,B);
  for(int64_t i=2;i<1000000;i++){
    if(X%i==0){
      Z++;
      while(X%i==0){
        X/=i;
      }
    }
  }
  if(X>1){
    Z++;
  }
  cout<<Z<<endl;
}