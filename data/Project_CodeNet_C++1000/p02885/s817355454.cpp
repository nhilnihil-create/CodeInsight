#include <iostream>
using namespace std;
int main(){
  int a,b;
  
  cin>>a>>b;
  
  int c=b*2;
  
  int d=a-c;
  
  if(d<=0)
    cout<<"0";
  else
    cout<<d;
  
  return 0;
}
