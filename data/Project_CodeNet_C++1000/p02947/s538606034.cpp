#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];

    sort(s[i].begin(), s[i].end());
  }

  map<string, int> temp;

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    temp[s[i]]++;
    if (temp[s[i]] != 1) ans += (temp[s[i]] - 1);
  }
  cout << ans << endl;
}