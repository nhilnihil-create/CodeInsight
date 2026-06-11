/*input
475254
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n;
  cin >> n;
  string s;
  while (n > 0) {
    n--;
    s += 'a'+n%26;
    n /= 26;
  }
  reverse(s.begin(), s.end());
  cout << s << endl;
}