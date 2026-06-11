#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <cmath>
#include <algorithm>

typedef long long ll;
typedef long double ld;

using namespace std;
int main()
{
  string s, t, u;
  int a, b;

  cin >> s >> t >> a >> b >> u;

  if (s == u) a -= 1;
  else b -= 1;

  cout << a << " " << b << endl;
  return 0;
}
