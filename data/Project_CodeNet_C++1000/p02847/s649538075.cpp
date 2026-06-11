#include<iostream>
#include<string>

int main(){
  std::string str;
  std::cin>>str;
  if(str=="SUN"){
    std::cout<<7<<std::endl;
  }
  if(str=="MON"){
    std::cout<<6<<std::endl;
  }
  if(str=="TUE"){
    std::cout<<5<<std::endl;
  }
  if(str=="WED"){
    std::cout<<4<<std::endl;
  }
  if(str=="THU"){
    std::cout<<3<<std::endl;
  }
  if(str=="FRI"){
    std::cout<<2<<std::endl;
  }
  if(str=="SAT"){
    std::cout<<1<<std::endl;
  }
  return 0;
}