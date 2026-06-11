#include<iostream>
#include<vector>
#include<algorithm>
signed main(){
  int n;
  std::cin>>n;
  std::vector<int> a(n);
  for(auto& ai:a)std::cin>>ai;
  auto b = a;
  std::sort(std::begin(b),std::end(b),std::greater<>());
  for(auto ai:a){
    if(ai==b[0])std::cout<< b[1] <<std::endl;
    else std::cout<< b[0] <<std::endl;
  }
}