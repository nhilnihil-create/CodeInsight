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
  int n, a[110];
  cin >> n;

  for (int i = 0; i < n; ++i)
  {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i)
  {
    if (a[i] % 2 == 0 && (a[i] % 3 != 0 && a[i] % 5 != 0))
    {
      cout << "DENIED" << endl;
      return 0;
    }
  }

  cout << "APPROVED" << endl;
  return 0;
}
