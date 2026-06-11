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
  unordered_map<int, int> p;
  int n, k, a[100010], q;
  cin >> n >> k >> q;
  for (int i = 0; i < q; ++i) cin >> a[i];
  for (int i = 0; i < q; ++i) ++p[a[i] - 1];
  for (int i = 0; i < n; ++i)
    if (k - q + p[i] > 0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
}
