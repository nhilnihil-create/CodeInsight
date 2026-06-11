#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '?') s[i] = 'D';
  }
  cout << s << endl;
  return 0;
}