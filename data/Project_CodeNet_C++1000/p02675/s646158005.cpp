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
  int n;
  cin >> n;
  n %= 10;
  string ans = "hon";
  if (n == 3) {
    ans = "bon";
  } else if (n == 0 || n == 1 || n == 6 || n == 8) {
    ans = "pon";
  }
  cout << ans << endl;
  return 0;
}