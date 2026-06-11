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
  int n, k, h[100010], cnt = 0;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> h[i];
  for (int i = 0; i < n; ++i) if (h[i] >= k) ++cnt;
  cout << cnt;
}
