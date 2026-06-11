#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;

  queue<string> q;
  q.push("a");

  while (q.size() != 0) {
    string s = q.front();
    if (s.size() == n)
      cout << s << endl;
    else {
      int x = 'a';
      for (int i = 0; i < s.size(); i++) x = max(x, (int)s[i]);
      for (int i = 'a'; i <= x + 1; i++) q.push(s + (char)i);
    }
    q.pop();
  }
}