#include <bits/stdc++.h>
using namespace std;
 
long long n, a, b, c, d;
string s;
 
bool solve() {
  a--; b--; c--; d--;
  bool ch = 0;
  for(int i = a + 1; i <= c; ++i)
    if(s[i] == s[i - 1] && s[i] == '#') return 0;
  for(int i = b + 1; i <= d; ++i)
    if(s[i] == s[i - 1] && s[i] == '#') return 0;
  if(c < d) return 1;
  for(int i = b; i <= d; ++i)
    if(i > 0 && i + 1 < n && s[i - 1] == s[i] &&
       s[i] == s[i + 1] && s[i] == '.')
      ch = 1;
  return ch;
}

int main() {
  cin >> n >> a >> b >> c >> d;
  cin >> s;
  if(solve())
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
 