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

  vector<int> P(N);
  rep(i, N) cin >> P[i];

  vector<int> P2 = P;
  std::sort(P2.begin(), P2.end());
  int count = 0;
  rep(i, N)
  {
    if (P[i] != P2[i])
      count++;
  }

  if (count == 0 || count == 2)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
