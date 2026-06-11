#include<iostream>
using namespace std;
int main(){
 
  int X;
  cin>>X;
  if(X-(X/100)*100<=5*(X/100))cout<<1;
  else cout<<0;
  return 0;
}