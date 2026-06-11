#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

string s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  bool ok = true;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == ((i & 1) ? 'R' : 'L')) {
      ok = false;
      break;
    }
  }
  if (ok)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  return 0;
}
