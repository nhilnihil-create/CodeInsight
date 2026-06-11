#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef long double ld;

using namespace std;
int main()
{
  int n, b[110], sum;
  cin >> n;
  for (int i = 0; i < n - 1; ++i) cin >> b[i];
  sum = b[0];
  for (int i = 0; i < n - 1; ++i)
  {
    if (i != n - 2)
    {
      if (b[i] > b[i + 1]) sum += b[i + 1];
      else sum += b[i];
    }
    else
      sum += b[i];
  }
  cout << sum;
}
