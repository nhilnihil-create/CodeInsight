#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  int N, L;
  cin >> N >> L;

  int sum = 0;
  rep(i, N)
  {
    sum += L + i;
  }

  int mn = 200000;
  int rest_;
  rep(i, N)
  {
    int now = L + i;
    int rest = sum - now;
    int diff = std::abs(rest - sum);

    if (mn > diff)
    {
      mn = diff;
      rest_ = rest;
    }
  }

  cout << rest_ << endl;

  return 0;
}
