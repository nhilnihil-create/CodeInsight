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
  int n, d[60], sum = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> d[i];
  for (int i = 0; i < n - 1; ++i)
  {
    for (int j = i + 1; j < n; ++j)
    {
      sum += d[i] * d[j];
    }
  }
  cout << sum;
}
