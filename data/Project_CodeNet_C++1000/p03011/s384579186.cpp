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
  int P, Q, R;
  cin >> P >> Q >> R;

  cout << std::min({P + Q, Q + R, P + R}) << endl;

  return 0;
}
