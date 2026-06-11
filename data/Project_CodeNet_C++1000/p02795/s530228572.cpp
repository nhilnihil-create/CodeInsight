#include<stdio.h>
#include<iostream>

int main(){
  int h, w, n;
  int ans;
  
  std::cin>>h>>w>>n;
  int div = fmax(h,w);
  if(n%div ==0){
  ans= n/div;
  }else{
  ans = (n/div)+1;
  }
  
  
  std::cout<<ans<<std::endl;
  
  
 return 0; 
}