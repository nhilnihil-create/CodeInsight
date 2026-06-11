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
  int A, B;
  cin >> A >> B;

  if (B == 1)
    cout << 0 << endl;
  else if (B <= A)
    cout << 1 << endl;
  else
  {
    B -= A;
    A--;
    cout << 1 + (B + (A - 1)) / A << endl;
  }

  return 0;
}
