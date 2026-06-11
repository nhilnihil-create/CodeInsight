#include <bits/stdc++.h>
using namespace std;

vector<int> z_algorithm(const string &s) {
  int n = s.size();
  vector<int> res(n);
  res.at(0) = n;
  int i = 1, j = 0;
  while (i < n) {
    while (i + j < n && s.at(j) == s.at(i + j)) j++;
    res.at(i) = j;
    if (j == 0) {
      i++;
      continue;
    }
    int k = 1;
    while (i + k < n && k + res.at(k) < j) res.at(i + k) = res.at(k), k++;
    i += k, j -= k;
  }
  return res;
}

int main() {
  int N;
  string S;
  cin >> N >> S;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    string tmp = S.substr(i);
    auto lcp = z_algorithm(tmp);
    for (int j = 0; j < (int) tmp.size(); j++) {
      int l = min(lcp.at(j), j);
      ans = max(ans, l);
    }
  }
  cout << ans << "\n";
}