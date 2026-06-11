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
  ll n, k, s = 0;
  cin >> n >> k;
  while (n >= (ll)pow(k, s)) ++s;
  cout << s << endl;
  return 0;
}
