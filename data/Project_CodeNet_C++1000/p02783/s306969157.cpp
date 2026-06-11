#include <iostream>
using namespace std;
int main(){
  int a,b;
  int t=1,i;
  cin>>a>>b;
  
  while(1){
    i=t*b;
    
    if(i>=a){
      break;
    }
    t++;
  }
  
  cout<<t;
      
  
  return 0;
}