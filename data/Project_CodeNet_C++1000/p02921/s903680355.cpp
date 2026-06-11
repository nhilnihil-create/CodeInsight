#include <iostream>
using namespace std;
int main(){
  int i,n=0;
  string a,b;
  
  cin>>a>>b;
  
  for(i=0;i<3;i++){
    if(a.at(i)==b.at(i))
      n++;
  }
  
  cout<<n;
  
  return 0;
}
