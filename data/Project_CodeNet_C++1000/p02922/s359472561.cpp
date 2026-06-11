#include<bits/stdc++.h>
using namespace std;

int main(){
  int A,B,count=1;
  cin>>A>>B;
  int a=A;
  if(B==1){
    cout<<0<<endl;
    return 0;
  }
  else{
    while(A<B){
      A=A-1+a;
      count++;
    }
  }
  cout<<count<<endl;
}