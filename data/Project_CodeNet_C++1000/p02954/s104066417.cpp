#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s; cin >> s;
  int sn = s.size();
  vector<int> a(sn);
  int rc=0, lc=0;
  for (int i=0; i<sn; i++) {
    if (s[i] == 'R') {
      rc++;
    } else {
      a[i-1] += rc;
      rc = 0;
    }
  }
  for (int i=sn-1; 0<=i; i--) {
    if (s[i] == 'L') {
      lc++;
    } else {
      a[i+1] += lc;
      lc = 0;
    }
  }
  for (int i=0; i<sn-1; i++) {
    if (s[i] == 'R' && s[i+1] == 'L') {
      int sum = a[i] + a[i+1];
      int flag;
      if (a[i] < a[i+1]) {
        flag = a[i+1] % 2;
        a[i] = sum / 2;
        a[i+1] = sum - a[i];
      } else {
        flag = a[i] % 2;
        a[i+1] = sum / 2;
        a[i] = sum - a[i+1];
      }
      if (flag == 0) swap(a[i], a[i+1]);
    }
  }
  for (int i=0; i<sn; i++) {
    cout << a[i];
    if (i != sn-1) cout << " ";
    else cout << endl;
  }
  return 0;
}