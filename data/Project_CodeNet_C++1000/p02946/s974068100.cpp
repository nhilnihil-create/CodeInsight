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
  int k, x;
  cin >> k >> x;
  for (int i = x - k + 1; i < x + k; ++i) cout << i << " ";
}
