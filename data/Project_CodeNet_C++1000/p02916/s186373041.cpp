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
  int n, a[30], b[30], c[30], point = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  for (int i = 0; i < n - 1; ++i) cin >> c[i];
  for (int i = 0; i < n; ++i)
  {
    point += b[a[i] - 1];
    if (i >= 1 && a[i - 1] + 1 == a[i])
    {
      point += c[a[i - 1] - 1];
    }
  }
  cout << point;
}
