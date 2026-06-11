#include <iostream>
 
using namespace std;
 
int main(){
  int A, B;
  cin >> A >> B;
  if(B==1){
    printf("0\n");
  }else if(A >= B){
    printf("1\n");
  }
  else{
    if((B-A)%(A-1)==0){
      printf("%d\n", 1 + (B-A)/(A-1));
    }else{
      printf("%d\n", 2 + (B-A)/(A-1));
    }
 
  }
}