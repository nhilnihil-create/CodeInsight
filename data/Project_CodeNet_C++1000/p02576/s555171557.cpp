#include <iostream>
using namespace std;
 
int main(){
  int n,x,t;
  cin >>n >> x >> t;
  int time =0;
  
  time = n/x;
  if(n%x>0){
    cout<<time*t+t;
  }else{
    cout<<time*t;
  }
  
  return 0;
}