#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  /*
  int n;
  cin >> n;
  map<string, int> list;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    string s;
    int t;
    cin >> s >> t;
    list[s] = t;
    sum += t;
  }
  string x;
  cin >> x;
  cout << sum - list[x] << endl;
  */

  int n;
  cin >> n;
  vector<pair<string, int>> list(n);
  for (int i = 0; i < n; i++) {
    cin >> list[i].first >> list[i].second;
  }
  string x;
  cin >> x;
  ll ans = 0;
  bool flag = 0;
  for (int i = 0; i < n; i++) {
    if (flag == true) ans += list[i].second;
    if (list[i].first == x) flag = true;
  }
  cout << ans << endl;
  return 0;
}