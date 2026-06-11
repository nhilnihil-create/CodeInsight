#include <iostream>
 
using namespace std;
 
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int ans=a+b<b+c?a+b:b+c;
  ans=ans<c+a?ans:c+a;
  cout<<ans<<endl;
}