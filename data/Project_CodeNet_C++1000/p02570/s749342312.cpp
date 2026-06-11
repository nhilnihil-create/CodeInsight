#include <iostream>
using namespace std;
int main(){
  double d,t,s;
  cin>>d>>t>>s;
  double tt=d/s;
  if(tt<=t){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
  return 0;
}