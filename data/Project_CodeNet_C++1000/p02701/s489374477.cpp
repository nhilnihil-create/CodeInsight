#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using ll = long long;
using namespace std;

int main() {
  map<string, int> mp;
  int n;
  cin >> n;
  string s;
  set<string> items;
  rep(i, n) {
    cin >> s;
    items.insert(s);
  }
  cout << items.size() << endl;
  return 0;
}