#include<iostream>
signed main(){
  int n,d;
  std::cin>>n>>d;
  auto ceil = [](int a,int b){return (a+b-1)/b;};
  std::cout<< ceil(n,2*d+1) <<std::endl;
}