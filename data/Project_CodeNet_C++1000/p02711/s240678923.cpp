#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string n;
  cin >> n;
  string ans = "No";
  rep(i, n.size()) {
    if (n.at(i) == '7') {
      ans = "Yes";
      break;
    }
  }

  cout << ans << endl;
}
