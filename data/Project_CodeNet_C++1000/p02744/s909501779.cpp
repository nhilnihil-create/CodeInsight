#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int n;

void dfs(string s) {
  int l = s.length();
  if (l == n) {
    cout << s << endl;
    return;
  }
  set<char> se;
  rep(i, l) se.insert(s[i]);
  char next = (*se.rbegin()) + 1;
  se.insert(next);
  for (auto c : se) {
    dfs(s + c);
  }
}

int main() {
  cin >> n;
  string ans = "";
  dfs("a");
}
