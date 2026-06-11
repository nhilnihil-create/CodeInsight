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
  int N;
  cin >> N;

  int num = 0;
  if (N < 10)
  {
    num = N;
  }
  else
  {
    num += 9;
    if (N < 100)
    {
    }
    else if (100 <= N && N < 1000)
    {
      num += N - 99;
      cout << num << endl;
      return 0;
    }
    else
    {
      num += 900;
      if (N < 10000)
      {
      }
      else if (10000 <= N && N < 100000)
      {
        num += N - 9999;
      }
      else
      {
        num += 90000;
      }
    }
  }

  cout << num << endl;

  return 0;
}
