#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<int> split(int i) {
  vector<int> ans;
  while (i > 0) {
    int digit = i % 10;
    i /= 10;
    ans.push_back(digit);
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int> > rules;

  rep(i, m) {
    int s, c;
    cin >> s >> c;
    rules.push_back(make_pair(s, c));
  }

  int first = 0;
  int last = 9;

  if (n > 1) {
    first = 1;
    rep(i, n - 1) {
      first = first * 10;
      last = last * 10 + 9;
    }
  }

  for (int i = first; i <= last; i++) {
    vector<int> digits = {0};
    if (i > 0) digits = split(i);
    int count = 0;

    for (auto rule : rules) {
      if (digits[rule.first - 1] == rule.second) {
        count++;
      } else {
        break;
      }
    }

    if (count == m) {
      cout << i << endl;
      return 0;
    }
  }

  cout << -1 << endl;

  return 0;
}
