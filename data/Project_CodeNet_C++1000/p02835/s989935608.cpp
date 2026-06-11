#include <iostream>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int d=a+b+c;
  
  if(d<=21)
    cout<<"win";
  else
    cout<<"bust";
  
  return 0;
}
