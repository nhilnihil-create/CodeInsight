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
  int N, D;
  cin >> N >> D;

  D = 2 * D + 1;
  cout << (N + (D - 1)) / D << endl;

  return 0;
}
