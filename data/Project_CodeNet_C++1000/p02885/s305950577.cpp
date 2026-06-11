#include<bits/stdc++.h>

int main()
{
  int A, B;
  std::cin >> A >> B;
  
  int length = A - (B * 2);
  if(length < 0)
    length = 0;
  
  std::cout << length << std::endl;
  
  return 0;
}