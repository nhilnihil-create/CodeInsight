#include<iostream>
#include<cmath>

using ll=long long;
using ld=long double;

int main(){
  ll a,b,c;
  std::cin>>a>>b>>c;
  ll d = c-a-b;
  if(d > 0 && (d*d > 4*a*b))
    std::cout<<"Yes\n";
  else
    std::cout<<"No\n";
}
