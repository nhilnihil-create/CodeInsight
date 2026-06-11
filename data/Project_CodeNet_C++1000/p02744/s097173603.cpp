#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

char biggest_char(string s) {
  char res = s[0];
  rep(i, s.size()) res = max(res, s[i]);
  return res;
}

int main() {
  int n;
  cin >> n;
  set<string> ans;
  queue<string> que;
  que.push("a");
  while (1) {
    string s = que.front();
    que.pop();
    if (s.size() > n) break;
    if (s.size() == n) ans.insert(s);
    char b = biggest_char(s);
    for (char c = 'a'; c <= b+1; ++c) {
      string ns = s + c;
      que.push(ns);
    }
  }
  for (auto itr = ans.begin(); itr != ans.end(); ++itr) cout << *itr << endl;
  return 0;
}