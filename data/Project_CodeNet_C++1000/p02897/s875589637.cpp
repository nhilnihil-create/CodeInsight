#include <iostream>
using namespace std;
int main(){
  
  int a;
  cin>>a;
  
  double b;
  
  if(a%2!=0){
    b=((double)(a+1)/2)/(double)a;
  }
  else{
    b=((double)a/2)/(double)a;
  }
  
  cout<<b;
  
  
  return 0;
}
