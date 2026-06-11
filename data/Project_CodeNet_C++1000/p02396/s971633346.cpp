#include<iostream>
using namespace std;
main(){
  int i=1,x;
  while(cin>>x){
    if(x==0)break;
    cout<<"Case "<<i<<": "<<x<<endl;
    i++;
  }
}