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
  ll cnt = 0;
  string s;
  cin >> s;
  for (ll i = 0; i < s.length(); ++i)
  {
    if (s[i] != s[s.length() - i - 1])
    {
      s[s.length() - i - 1] = s[i];
      ++cnt;
    }
  }
  cout << cnt;
}
