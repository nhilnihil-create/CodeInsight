#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

ll calc(ll n) {
  if (n == 1) return 1;
  return 2ll * calc(n / 2) + 1;
}

int main() {
  ll h;
  cin >> h;
  cout << calc(h) << endl;
  return 0;
}