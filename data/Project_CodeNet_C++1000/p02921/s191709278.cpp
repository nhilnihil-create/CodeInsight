#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int main () {
  vector<char> s(3);
  vector<char> t(3);
  int cnt=0;
  rep(i, 3) cin >> s.at(i);
  rep(i, 3) cin >> t.at(i);
  rep(i, 3) {
    if (s.at(i)==t.at(i)) cnt++;
  }
  cout << cnt << endl;
}
