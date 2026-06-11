#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s;
  cin >> s;

  long long result = 0;
  int i = 0;
  long long lt = 0;
  long long gt = 0;
  while (i < s.size()) {
    while (s[i] == '<') {
      lt++;
      i++;
    }
    while (s[i] == '>'){
      gt++;
      i++;
    }

    long long mx, mn;
    mx = max(gt, lt);
    mn = max(0LL, min(gt, lt) - 1);
    result += mx * (mx + 1) / 2;
    result += mn * (mn + 1) / 2;
    gt = 0;
    lt = 0;
  }

  cout << result << endl;
  return 0;
}