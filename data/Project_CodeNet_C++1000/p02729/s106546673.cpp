#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef long double ld;

using namespace std;
int main()
{
  int n, m, sum = 0;
  cin >> n >> m;

  if (n >= 2)
  {
    sum += n * (n - 1) / 2;
  }
  if (m >= 2)
  {
    sum += m * (m - 1) / 2;
  }

  cout << sum << endl;
  return 0;
}
