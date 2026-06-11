#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
  int x;
  cin >> x;

  while (1)
  {
    bool yes = true;
    // エラトステネス
    for (int i = 2; i < sqrt(x); i++)
    {
      if (x % i == 0)
      {
        yes = false;
        continue;
      }
    }
    if (yes)
    {
      break;
    }

    x++;
  }

  cout << x << endl;

  return 0;
}