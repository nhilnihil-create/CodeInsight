#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int main()
{
  int h, w, n;
  cin >> h >> w >> n;
  int m = max(h, w);
  int result = n / m;
  if (n % m) result++;
  cout << result << endl;
  return 0;
}
