#include <iostream>

int main()
{
  int a,b,c,k;
  std::cin >> a >> b >> c >> k;
  for (;k>0;--k)
  {
    if (a >= b)
    {
      b *= 2;
    }
    else if (b >= c)
    {
      c *= 2;
    }
    else
    {
      break;
    }
  }
  if (a < b && b < c)
  {
    std::cout << "Yes";
  }
  else
  {
  	std::cout << "No";
  }
  return 0;
}
