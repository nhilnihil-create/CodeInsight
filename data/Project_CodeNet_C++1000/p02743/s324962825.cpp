#include<stdio.h>
#include<iostream>

int main(){

  long long a, b, c;
  
  long long ans;
  
  std::cin>>a>>b>>c;
  
  if(c-(a+b)>0){
    long long r, l;
    
    r = (c-(a+b))*(c-(a+b));
    l = 4*a*b;
    
    if(r>l){
      std::cout<<"Yes";
    }else{
      std::cout<<"No";
    }
    
    
  }
  else{
    std::cout<<"No";
  }
  
}