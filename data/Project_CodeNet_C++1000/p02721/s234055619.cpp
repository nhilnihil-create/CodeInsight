#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  int n, k, c;
  string s;
  cin >> n >> k >> c >> s;
  vector < int > l, r;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'o' && l.size() < k) {
      l.push_back(i);
      i += c;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'o' && r.size() < k) {
      r.push_back(i);
      i -= c;
    }
  }
  reverse(r.begin(), r.end());
  for (int i = 0; i < l.size() && i < r.size(); i++) {
    if (l[i] == r[i]) cout << l[i] + 1 << endl;
  }
}
