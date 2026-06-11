#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll n;
void solve(string s, char c) {
  if (s.size() == n) {
    cout << s << endl;
    return;
  }
  for (char i = 'a'; i <= c; i++) solve(s + i, (i == c ? c + 1 : c));
}

int main() {
  cin >> n;
  solve("", 'a');
  return 0;
}
