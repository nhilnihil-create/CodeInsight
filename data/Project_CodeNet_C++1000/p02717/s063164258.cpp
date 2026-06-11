#include<iostream>
using namespace std;

int main(){

  int a,b,c;
  cin>>a>>b>>c;
  int temp;
  int temp2;
  
  temp = a;
  a = b;
  b = temp;
  
  temp2 = a;
  a = c;
  c = temp2;
  
  cout<<a<<" "<<b<<" "<<c;
  

}