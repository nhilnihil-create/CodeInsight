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
  int a, b, c;
  cin >> a >> b >> c;

  if ((a == b && a != c) || (a == c && a != b) || (c == b && a != c))
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }

  return 0;
}
