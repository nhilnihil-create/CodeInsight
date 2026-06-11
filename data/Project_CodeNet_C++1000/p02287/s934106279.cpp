#include <iostream>
using namespace std;

int main(){
  int a,b[300];
  cin>>a;
  for(int i=1;i<=a;i++){
    cin>>b[i];
  }
  for(int i=1;i<=a;i++){
    cout<<"node "<<i<<": key = "<<b[i]<<", ";
    if(i/2>0)cout<<"parent key = "<<b[i/2]<<", ";
    if(i*2<=a)cout<<"left key = "<<b[i*2]<<", ";
    if(i*2+1<=a)cout<<"right key = "<<b[i*2+1]<<", ";
    cout<<endl;
  }
  return 0;
}