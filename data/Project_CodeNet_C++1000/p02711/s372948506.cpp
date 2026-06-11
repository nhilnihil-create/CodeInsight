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
  string s;
  cin >> s;
  int ans = 0;
  ans += (s[0] == '7');
  ans += (s[1] == '7');
  ans += (s[2] == '7');
  cout << (0 < ans ? "Yes" : "No") << endl;
  return 0;
}