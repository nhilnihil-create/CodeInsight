#include<iostream>
using namespace std;

int main(){
  int A,B,C;
  
  cin>>A>>B>>C;
  
  int tmp = B;
  
  B = A;
  
  A = tmp;
  
  tmp = C;
  
  C = A;
  
  A = tmp;
  
  cout<<A<<" "<<B<<" "<<C;
  
  return 0;


}