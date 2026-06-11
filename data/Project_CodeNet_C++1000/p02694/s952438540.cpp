#include <bits/stdc++.h>

int main()
{
  long long a;
  std::cin >> a;
  long takahashi_money = 100;
  int count = 0;
  while(takahashi_money < a)
  {
    takahashi_money = takahashi_money + takahashi_money / 100;
    count++;
  }
  std::cout << count << std::endl;
  
  return 0;
}
