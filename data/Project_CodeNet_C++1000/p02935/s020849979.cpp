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
  int n, v[100];
  ld sum;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> v[i];
  sort(v, v + n);
  sum = v[0];
  for (int i = 1; i < n; ++i) sum = (sum + v[i]) / 2.0;
  cout << fixed << setprecision(15) << sum;
}
