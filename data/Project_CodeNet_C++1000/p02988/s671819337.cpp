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
  int n;
  cin >> n;

  vector<int> p(n);
  rep(i, n) cin >> p[i];

  int sum = 0;
  for (int i = 1; i < n - 1; i++)
  {
    int mn = std::min({p[i - 1], p[i], p[i + 1]});
    int mx = std::max({p[i - 1], p[i], p[i + 1]});
    if (p[i] != mn && p[i] != mx)
      sum++;
  }

  cout << sum << endl;

  return 0;
}
