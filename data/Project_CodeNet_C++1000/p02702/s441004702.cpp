#include <bits/stdc++.h>

using namespace std;
// (setq-default c-basic-offset 2)

int m = 2019;
int main() {
  string s;
  cin >> s;
  int n = s.size();
  reverse(s.begin(), s.end());
  int x = 1;
  int tot = 0;
  vector<int> cnt(m);
  long long ret = 0;

  for (int i = 0; i < n; ++i) {
    cnt[tot]++;

    tot = (tot + (s[i] - '0') * x) % m;
    x = (x * 10) % m;

    ret += cnt[tot];
  }
  cout << ret << endl;
  return 0;
}
