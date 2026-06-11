#include <bits/stdc++.h>

using namespace std;
// (setq-default c-basic-offset 2)

int main() {
  string s;
  // S = an... a2 a1
  cin >> s;

  // So that S = an-1 * 10^n-1 + ... + a0 * 10^0
  reverse(s.begin(), s.end());

  int n = s.size();

  // prefix sum mod 2019
  vector<int> sm(n + 1);

  // cnt[i] = how many prefix sum % 2019 == i
  vector<int> cnts(2019);
  cnts[0]++;

  int d = 1;
  for (int i = 0; i < n; ++i) {
    int digit = s[i] - '0';
    sm[i + 1] = ((digit * d) % 2019 + sm[i]) % 2019;
    d = (10 * d) % 2019;

    cnts[sm[i + 1]]++;
  }

  int ret = 0;

  // how many pairs for every resisual mod 2019
  // n choose 2 = n * (n-1) / 2
  for (int cnt : cnts) {
    ret += cnt * (cnt - 1) / 2;
  }
  cout << ret << endl;
  return 0;
}
