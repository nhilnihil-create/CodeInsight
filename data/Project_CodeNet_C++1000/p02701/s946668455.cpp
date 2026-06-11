#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  set<string> s;
  for (int i = 0; i < n; i++) {
    string a;
    cin >> a;
    if (s.count(a) == 0) {
      s.insert(a);
    }
  }

  cout << s.size() << endl;
  return 0;
}