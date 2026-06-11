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
  int cnt = 0;
  string s, t;
  cin >> s >> t;
  for (int i = 0; i < 3; ++i) if (s[i] == t[i]) ++cnt;
  cout << cnt;
}
