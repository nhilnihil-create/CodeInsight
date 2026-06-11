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
  int a, b, c;
  cin >> a >> b >> c;
  cout << (a + b + c >= 22 ? "bust" : "win");
}
