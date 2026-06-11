#include <iostream>
  
int main()
{
int a, b, c;
std::cin >> a >> b >> c;

std::string result = a < b && b < c ? "Yes" : "No";
std::cout << result << std::endl;

return 0;
}