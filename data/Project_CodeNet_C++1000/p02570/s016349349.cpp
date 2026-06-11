#include <iostream>

int main()
{
  float Distance = 0;
  float Speed = 0;
  float Time = 0;
  
  std::cin >> Distance >> Time >> Speed;
  
  if(Distance <= Time * Speed)
  {
    std::cout << "Yes" << std::endl;
  }
  else 
  {
    std::cout << "No" << std::endl;
  }
  return 0;
}