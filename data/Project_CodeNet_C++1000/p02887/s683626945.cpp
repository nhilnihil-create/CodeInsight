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
  int n, sum = 1;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n - 1; ++i) if (s[i] != s[i + 1]) ++sum;
  cout << sum;
}
