#include<iostream>
using namespace std;
int main(){

  int A,B;
  int realA,realB;
  cin>>A>>B;
  for(int i=1;i<=2000;i++){
  
    realA=i*0.08;
    realB=i*0.1;
    if(realA==A&&realB==B){
    
      cout<<i;
      return 0;
    }
  }
  cout<<-1;
  return 0;
}