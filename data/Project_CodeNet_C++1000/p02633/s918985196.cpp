#include <iostream>
int main(){
  int n;
  std::cin>>n;
  int cnt = 0;
  int now = 0;
  while(!now || now % 360 != 0){now += n;cnt++;}
  std::cout<<cnt;
  return 0;
}