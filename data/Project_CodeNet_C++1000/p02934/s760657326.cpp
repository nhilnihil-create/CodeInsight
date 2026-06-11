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
  int n, a[110];
  ld sum = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) sum += 1 / (ld)a[i];
  cout << fixed << setprecision(15) << 1 / (ld)sum;
}
