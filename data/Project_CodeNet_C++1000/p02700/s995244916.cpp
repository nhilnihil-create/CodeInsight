#include<iostream>
using namespace std;
int main(){
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  while(c&&a){
    c=c-b;
    if(c<=0){
      cout<<"Yes";
      break;
    }
    a=a-d;
    if(a<=0){
      cout<<"No";
      break;
    }
  }
  return 0;
 }
    