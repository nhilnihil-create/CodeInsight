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
  int K, X;
  cin >> K >> X;

  int mn = X - (K - 1);
  int mx = X + (K - 1);

  for (int i = mn; i < mx; i++)
  {
    cout << i << " ";
  }
  cout << mx << endl;

  return 0;
}
