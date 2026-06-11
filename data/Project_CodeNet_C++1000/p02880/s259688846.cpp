#include <bits/stdc++.h>
using namespace std;

int main()
{
  int	n, flag = 0;
  
  cin >> n;
  for (int i = 1; i <= 9; i++)
  {
    for (int j = 1; j <= 9; j++)
    {
      if (i * j == n)
        flag = 1;
    }
  }
  if (flag == 1)
    cout << "Yes\n";
  else
    cout << "No\n";
  return (0);
}