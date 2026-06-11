#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

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
  vector<int> H(N);
  rep(i, N) cin >> H[i];
  int mx = 0;
  int count = 0;
  rep(i, N - 1)
  {
    if (H[i] >= H[i + 1])
      count++;
    else
      count = 0;

    mx = std::max(mx, count);
  }

  cout << mx << endl;

  return 0;
}
