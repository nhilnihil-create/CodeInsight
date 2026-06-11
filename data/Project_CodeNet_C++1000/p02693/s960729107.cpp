#include <iostream>

int main()
{
  int k, a, b;
  std::cin >> k >> a >> b;
  std::string res = "NG";
  
  for(std::size_t i = a; i <= b; ++i)
  {
    if((i % k) == 0)
    {
      res = "OK";
      break;
    }
  }
  std::cout << res;
  return 0;
}