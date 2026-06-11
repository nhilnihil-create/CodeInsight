#include <iostream>

int main(){
  int a[6] = {500,100,50,10,5,1};
  int n;
  while(std::cin>>n){
    if(!n)break;
    n=1000-n;
    int res = 0;
    for(int i=0;i<6;i++){
      res = res + n / a[i];
      n = n % a[i];
    }
    std::cout<<res<<std::endl;
  }
}