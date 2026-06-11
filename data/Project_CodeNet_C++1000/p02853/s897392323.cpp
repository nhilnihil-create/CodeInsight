#include <iostream>
using namespace std;
int main(){
  int x,y;
  cin>>x>>y;
  int ans=0;
  ans+=max((4-x)*100000,0);
  ans+=max((4-y)*100000,0);
  if(ans==600000)ans=1000000;
  cout <<ans<<endl;
}
