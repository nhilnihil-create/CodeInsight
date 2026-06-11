#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  string s;
  cin >> s;
  if (s.size() % 2 != 0) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i < s.size(); i += 2) {
    if (s[i] != 'h' || s[i + 1] != 'i') {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}