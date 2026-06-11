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

int main() {
  ll n;
  cin >> n;
  n--;
  string ans = "";
  while (0 <= n) {
    ll r = n % 26;
    ans += (char)(r + 'a');
    n = n / 26;
    n--;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}