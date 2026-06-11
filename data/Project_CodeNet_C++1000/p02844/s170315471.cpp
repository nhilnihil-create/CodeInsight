#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> c(3);
  int cnt = 0;
  for (int i = 0; i < 1000; ++i) {
    c[2] = i / 100;
    c[1] = (i / 10) % 10;
    c[0] = i % 10;

    int f = 0;
    for (int j = 0; j < n; ++j) {
      if (s[j] == ('0' + c[f])) f++;
      if (f == 3) break;
    }
    if (f == 3) cnt++;
  }
  cout << cnt << endl;
}
