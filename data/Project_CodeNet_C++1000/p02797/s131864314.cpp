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
  int n, k, s;
  cin >> n >> k >> s;
  int rest = s + 1;
  if (s + 1 > 1e9) rest = 1;
  for (int i = 0; i < n; ++i) {
    if (i) cout << " ";
    int cur = s;
    if (i >= k) cur = rest;
    cout << cur;
  }
  return 0;
}
