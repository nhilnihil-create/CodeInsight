#include <bits/stdc++.h>
using namespace std;
int main() {
  int h, n, ttl;
  cin >> h >> n;
  ttl = 0;
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec.at(i);
    ttl += vec.at(i);
  }
  if (ttl>=h) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
