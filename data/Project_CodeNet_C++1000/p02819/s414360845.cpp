#include<iostream>
using namespace std;
int main(){
 
  int X;
  cin>>X;
  if(X==2){
    
    cout<<2;
    return 0;
  }
  else{
    if(X%2==0)X++;
  }
  bool flag=0;
  while(flag==0){

    flag=1;
    for(int i=3;i<=X/2+1;i+=2){
    
      if(X%i==0){

        flag=0;
        X+=2;
        break;
      }
    }
  }
  cout<<X;
  return 0;
}