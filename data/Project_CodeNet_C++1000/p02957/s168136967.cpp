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
  int A, B;
  cin >> A >> B;

  int mx = std::max(A, B);
  int mn = std::min(A, B);
  if ((mx - mn) % 2 == 0)
  {
    cout << mn + (mx - mn) / 2 << endl;
  }
  else
  {
    cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}
