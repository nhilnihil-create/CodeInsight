#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<string>> res(n);
  res.at(0).push_back("a");
  for (int i=1; i<n; ++i) {
    for (string s : res.at(i-1)) {
      char end = 0;
      for (char c : s) if (end < c) end = c;
      ++end;
      for (char c='a'; c<=end; ++c) {
        res.at(i).push_back(s+c);
      }
    }
  }
  for (string s : res.at(n-1)) cout << s << endl;
  return 0;
}
