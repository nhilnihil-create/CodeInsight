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
  int a, b, cnt = 0;
  cin >> a >> b;
  while (a * cnt - (cnt - 1) < b) ++cnt;
  cout << cnt;
}
