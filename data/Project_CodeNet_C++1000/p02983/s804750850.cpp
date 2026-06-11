#include <iostream>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int L, R;
  cin >> L >> R;

  if (R - L >= 2019)
  {
    cout << 0 << endl;
    return 0;
  }

  L %= 2019;
  R %= 2019;
  if (L >= R)
  {
    cout << 0 << endl;
    return 0;
  }

  int mn = 2020;
  for (int i = L; i < R; i++)
  {
    for (int j = i + 1; j <= R; j++)
    {
      int m = i * j % 2019;
      if (mn > m)
        mn = m;
    }
  }

  cout << mn << endl;

  return 0;
}
