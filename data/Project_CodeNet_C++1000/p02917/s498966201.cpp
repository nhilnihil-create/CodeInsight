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
  int N;
  cin >> N;
  vector<int> B(N);
  for (int i = 1; i < N; i++)
  {
    cin >> B[i];
  }

  long long sum = 0;
  sum += B[1];
  for (int i = 1; i < N - 1; i++)
  {
    sum += std::min(B[i], B[i + 1]);
  }
  sum += B[N - 1];

  cout << sum << endl;

  return 0;
}
