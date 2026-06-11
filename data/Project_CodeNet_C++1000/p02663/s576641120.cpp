#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <stdio.h>

int main(void){
  int h1,m1,h2,m2,t,k;
  std::cin >>h1>>m1>>h2>>m2>>k;

  t=(h2-h1)*60+(m2-m1);
  
  if(t==k){
    std::cout << "0"; 
  }else{
    std::cout << t-k;
  }
  return 0;
}