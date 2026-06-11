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
  ll n, a[200010], cnt = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) if (cnt + 1 == a[i]) ++cnt;
  if (cnt == 0) cout << "-1";
  else cout << n - cnt;
}
