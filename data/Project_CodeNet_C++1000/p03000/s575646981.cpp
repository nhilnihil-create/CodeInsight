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
  int N, X;
  cin >> N >> X;

  int bo = 1;
  int sum = 0;
  rep(i, N)
  {
    int l;
    cin >> l;
    sum += l;
    if (sum <= X)
    {
      bo++;
    }
  }

  cout << bo << endl;

  return 0;
}
