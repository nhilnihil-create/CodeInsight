#include<iostream>
using ll=long long;

int main(){
  ll h,v;
  std::cin>>h>>v;
  ll r = (h*v)%2;
  if(h==1 || v==1)
    std::cout<<1<<std::endl;
  else{
    if(r==1)
    std::cout<<((ll)(h*v)/2)+1<<std::endl;
    else
    std::cout<<((ll)(h*v)/2)<<std::endl;
  }
}
