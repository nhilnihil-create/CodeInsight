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
  int n;
  string s, t;
  cin >> n >> s >> t;
  for (int i = 0; i < n; ++i)
  {
    cout << s[i] << t[i];
  }
}
