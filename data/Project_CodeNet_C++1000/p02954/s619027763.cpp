#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  string s; cin >> s;
  int n = s.size();
	vector<int> evn(n, 0), odd(n, 0);
	for (int i = 0; i < n - 1; i++) {
    if (s[i] != 'R') continue;
		int j = i;
    while (s[j + 1] == 'R') j++;
    int c = j - i + 1;
    if (c % 2 == 0) {
      evn[j] += c / 2;
      evn[j + 1] += c / 2;
    } else {
      evn[j] += c / 2 + 1;
      evn[j + 1] += c / 2;
    }
    i = j;
	}
  for (int i = n - 1; i > 0; i--) {
    if (s[i] != 'L') continue;
    int j = i;
    while (s[j - 1] == 'L') j--;
    int c = i - j + 1;
    if (c % 2 == 0) {
      evn[j] += c / 2;
      evn[j - 1] += c / 2;
    } else {
      evn[j] += c / 2 + 1;
      evn[j - 1] += c / 2;
    }
    i = j;
  }
  for (int i = 0; i < n; i++) {
    cout << evn[i] << ' ';
  }
  cout << '\n';
}
