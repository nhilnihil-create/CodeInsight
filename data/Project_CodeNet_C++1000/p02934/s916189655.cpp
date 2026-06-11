#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

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

  long double div = 0;
  rep(i, N)
  {
    div += 1 / (long double)A[i];
  }

  cout << std::fixed << std::setprecision(10) << 1 / div << endl;

  return 0;
}
