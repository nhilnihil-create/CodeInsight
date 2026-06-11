#include<bits/stdc++.h>
#define REP(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;

int main() {
  int n, c = 0;
  cin >> n;

  string s[n], si, x;
  int t[n], ti;
  REP(i, n) cin >> s[i] >> t[i];
  cin >> x;

  bool f = false;
  REP(i, n) {
    if (s[i] == x) {
      f = true;
      continue;
    }
    if (!f) continue;
    c += t[i];
  }

  cout << c << endl;
  return 0;
}