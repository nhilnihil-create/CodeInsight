#include<bits/stdc++.h>

int main()
{
  int A, B;
  std::cin >> A >> B;
  
  int ans = -1;
  if((A < 10) && (B < 10))
    ans = A * B;
  
  std::cout << ans << std::endl;
  
  return 0;
}