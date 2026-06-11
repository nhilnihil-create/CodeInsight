#include<iostream>

int main(){
  long long int a,b;
  std::cin>>a>>b;
  if(a*b%2==1&&a!=1&&b!=1){
    std::cout<<(a*b+1)/2<<std::endl;
  }else if(a!=1&&b!=1){
    std::cout<<a*b/2<<std::endl;
  }else std::cout<<1<<std::endl;
  return 0;
}


