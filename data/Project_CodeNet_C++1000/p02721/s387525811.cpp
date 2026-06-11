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
  int n, k, c;
  cin >> n >> k >> c;
  string s;
  cin >> s;
  vector<int> cand1(k, -1), cand2(k, -1);
  int day = 0;
  for (int i = 0; i < n; ++i) {
    if (k <= day) break;
    if (s[i] == 'o') {
      if (day == 0 || cand1[day - 1] + c + 1 <= i) {
        cand1[day] = i;
        day++;
      }
    }
  }
  day = k - 1;
  for (int i = n - 1; i >= 0; --i) {
    if (day <= -1) break;
    if (s[i] == 'o') {
      if (day == k - 1 || i <= cand2[day + 1] - c - 1) {
        cand2[day] = i;
        day--;
      }
    }
  }
  for (int i = 0; i < k; ++i) {
    if (cand1[i] == cand2[i]) {
      cout << cand1[i] + 1 << endl;
    }
  }
  return 0;
}