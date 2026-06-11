#include <iostream>
#include <string>
#include <vector>
#include <cmath>

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
  vector<int> W(N);
  rep(i, N) cin >> W[i];

  vector<int> left(N + 1);
  vector<int> right(N + 1);
  left[0] = 0;
  right[N] = 0;

  int sum = 0;
  rep(i, N)
  {
    sum += W[i];
    left[i + 1] = sum;
  }

  sum = 0;
  rep(i, N)
  {
    sum += W[N - 1 - i];
    right[N - 1 - i] = sum;
  }

  int mn = 1000000000;
  rep(i, N + 1)
  {
    int tmp = std::abs(left[i] - right[i]);
    if (mn > tmp)
      mn = tmp;
  }

  cout << mn << endl;

  return 0;
}
