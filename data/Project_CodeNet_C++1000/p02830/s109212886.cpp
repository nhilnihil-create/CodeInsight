#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
int main() {
  int n;
  string s, t;
  cin >> n >> s >> t;

  for (int i = 0; i < n; i++) {
    cout << s[i] << t[i];
  }
  cout << endl;
}