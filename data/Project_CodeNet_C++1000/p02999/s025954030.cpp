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
  int X, A;
  cin >> X >> A;

  if (X < A)
    cout << 0 << endl;
  else
    cout << 10 << endl;

  return 0;
}
