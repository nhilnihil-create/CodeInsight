#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;
using P = pair<char, int>;

int main() {
  string s;
  cin >> s;
  vector<P> v;
  rep(i, s.size()) {
    int count = 1;
    while (i < (int)s.size() - 1 && s[i] == s[i + 1]) {
      count++;
      i++;
    }
    v.emplace_back(P(s[i], count));
  }

  vector<int> counts(s.size(), 0);
  int index = 0;
  for (auto p : v) {
    int odd = (p.second + 1) / 2;
    int even = p.second - odd;
    if (p.first == 'R') {
      counts[index + p.second - 1] += odd;
      counts[index + p.second] += even;
    } else {
      counts[index] += odd;
      counts[index - 1] += even;
    }
    index += p.second;
  }
  rep(i, s.size()) {
    if (i != s.size() - 1) {
      cout << counts[i] << " ";
    } else {
      cout << counts[i] << endl;
    }
  }
  return 0;
}
