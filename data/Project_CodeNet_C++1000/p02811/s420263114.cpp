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
  ll k, x;
  cin >> k >> x;
  cout << (k * 500 >= x ? "Yes" : "No");
}
