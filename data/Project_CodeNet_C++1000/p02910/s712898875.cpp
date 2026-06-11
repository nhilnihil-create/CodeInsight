#include <iostream>

using namespace std;

int main()
{
  string s;
  cin >> s;

  bool success = true;
  for (size_t i = 0; i < s.size(); i++)
  {
    if ((i + 1) % 2 == 0)
    {
      //偶数
      if (s[i] == 'R')
      {
        success = false;
      }
    }
    else
    {
      if (s[i] == 'L')
      {
        success = false;
      }
    }
  }

  if (success)
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

  return 0;
}