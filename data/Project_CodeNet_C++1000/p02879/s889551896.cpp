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
  int a, b;
  cin >> a >> b;
  if (a > 9 || b > 9)
  {
    cout << "-1";
  }
  else
  {
    cout << a * b;
  }
}
