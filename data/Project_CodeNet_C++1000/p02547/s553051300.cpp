#include <bits/stdc++.h>
using namespace std;

int main()
{
  int	n, flag = 0;
  
  cin >> n;
  vector<int>	d1(n), d2(n);
  
  for(int i = 0; i < n; i++)
    cin >> d1.at(i) >> d2.at(i);
  for(int i = 0; i < n; i++)
  {
    if (d1.at(i) == d2.at(i))
      flag++;
    else
      flag = 0;
    if (flag == 3)
      break;
  }
  if (flag == 3)
    cout << "Yes\n";
  else
    cout << "No\n";
  return (0);
}