#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <unordered_map>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef long double ld;

using namespace std;
int main()
{
  ll a, b, asum, bsum;
  cin >> a >> b;
  asum = a;
  bsum = b;
  while (asum != bsum)
  {
    if (asum > bsum) bsum += b;
    else asum += a;
  }

  cout << asum;
}
