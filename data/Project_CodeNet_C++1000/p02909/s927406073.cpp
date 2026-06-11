#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  if (s == "Sunny") cout << "Cloudy\n";
  else if (s == "Cloudy") cout << "Rainy\n";
  else cout << "Sunny\n";

  return (0);
}
