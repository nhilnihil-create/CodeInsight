#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

  vector<int> mon(N + 1);
  rep(i, N + 1)
  {
    cin >> mon[i];
  }

  vector<int> hero(N);
  rep(i, N)
  {
    cin >> hero[i];
  }

  long long defeat = 0;
  rep(i, N)
  {
    if (hero[i] > mon[i])
    {
      defeat += mon[i];
      int diff = hero[i] - mon[i];
      defeat += std::min(diff, mon[i + 1]);
      mon[i + 1] = std::max(0, mon[i + 1] - diff);
    }
    else
    {
      defeat += hero[i];
    }
  }
  cout << defeat << endl;

  return 0;
}
