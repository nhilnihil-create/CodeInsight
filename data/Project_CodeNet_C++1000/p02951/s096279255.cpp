#include <iostream>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  
  int d=a-b;
  int e=min(c,d);
  int f=c-e;
  
  cout<<f;
  return 0;
}
