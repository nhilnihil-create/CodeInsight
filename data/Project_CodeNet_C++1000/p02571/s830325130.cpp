// Problem URL: https://atcoder.jp/contests/abc177/tasks/abc177_b
#include <bits/stdc++.h>
using namespace std;

int main()
{
  string s, t;
  getline(cin, s);
  getline(cin, t);
  int minimum = t.size();
  for (int i = 0; i < s.size() - t.size() + 1; i++) {
    int minCount = 0;
    for (int j = 0; j < t.size(); j++) {
      if (s[i + j] != t[j]) {
        minCount++;
      }
    }
    minimum = min(minCount, minimum);
  }
  cout << minimum;
  return 0;
}
