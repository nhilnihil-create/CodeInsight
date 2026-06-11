#include <bits/stdc++.h>
//#include "atcoder/all"
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
const ll mod = 1e9 + 7;
int main() {
  string s;
  cin >> s;

  if (s.back() == 's') {
    cout << s + "es" << endl;
  } else {
    cout << s + "s" << endl;
  }
}