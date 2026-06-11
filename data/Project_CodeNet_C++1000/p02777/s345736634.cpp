#include <iostream>
using namespace std;
int main(){
  string a,b,c;
  int d,e;
  
  cin>>a>>b;
  cin>>d>>e;
  cin>>c;
  
  if(c==a)
    cout<<d-1<<' '<<e;
  else 
    cout<<d<<' '<<e-1;
  
  return 0;
}