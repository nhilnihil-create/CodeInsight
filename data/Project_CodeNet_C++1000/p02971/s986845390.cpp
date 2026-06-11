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
  vector<int> A(N);
  rep(i, N) cin >> A[i];

  int mx = 0;
  int mx2 = 0;
  rep(i, N)
  {
    if (mx < A[i])
    {
      mx2 = mx;
      mx = A[i];
    }
    else if (mx2 < A[i])
    {
      mx2 = A[i];
    }
  }

  rep(i, N)
  {
    if (A[i] == mx)
      cout << mx2 << endl;
    else
      cout << mx << endl;
  }

  return 0;
}
