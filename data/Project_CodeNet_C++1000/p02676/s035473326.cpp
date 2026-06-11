#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
int main() {
  int k;
  string s;
  cin >> k >> s;

  if (s.size() <= k) {
    cout << s << endl;
    return 0;
  } else {
    for (int i = 0; i < k; i++) {
      cout << s[i];
    }
    cout << "..." << endl;
  }
}