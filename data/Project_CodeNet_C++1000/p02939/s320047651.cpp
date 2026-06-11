#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  string k = "", t = "";
  int cnt = 0;
  for (int i = 0; i < s.length(); i++) {
    k.push_back(s[i]);
    if (k != t) {
      t = k;
      k = "";
      cnt++;
    }
  }
  cout << cnt << endl;
}