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

  vector<int> d(N);
  rep(i, N) cin >> d[i];

  std::sort(d.begin(), d.end());

  cout << d[N / 2] - d[N / 2 - 1] << endl;

  return 0;
}
