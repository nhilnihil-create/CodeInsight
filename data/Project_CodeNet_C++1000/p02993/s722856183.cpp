#include <iostream>
#define NUM 4
using namespace std;
int main(){
  int a;
  cin>>a;
  
  int b[NUM];
  for(int i=0;i<NUM;i++){
    b[i]=a%10;
    a=a/10;
  }
  
  for(int i=0;i<NUM;i++){
    if(i==3){
      cout<<"Good";
      break;
    }
    
    else if(b[i]==b[i+1]){
      cout<<"Bad";
      break;
    }
  }
    return 0;
}
