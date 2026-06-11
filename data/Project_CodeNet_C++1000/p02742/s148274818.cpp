#include<stdio.h>
#include<iostream>

int main(){

  long long H, W;
  
  long long ans;
  
  std::cin>>H>>W;
  if(H==1 || W==1){
    std::cout<<"1";
  }
  else if(H%2 == 0){
    ans= (H/2)*W;
    std::cout<<ans;
  }
  else if(W%2 == 0){
    std::cout<<(W/2)*H;
  }
    
  else{
  	std::cout<<(H*W/2)+1;
  }
  
}