#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;
  ll k;
  cin >> k;
  int n = s.size();
  string t = s + s;
  string u = s;
  bool a = true;
  rep(i,n-1) {
    if(s.at(i)!=s.at(i+1)) a = false;
  }
  if(a) {
    cout << n*k/2 << endl;
    return 0;
  }
  ll cnt1 = 0;
  rep(i,n-1) {
    if(s.at(i)==s.at(i+1)) {
      s.at(i+1) = 'A';
      cnt1++;
    }
  }
  ll cnt2 = 0;
  rep(i,t.size()-1) {
    if(t.at(i)==t.at(i+1)) {
      t.at(i+1) = 'A';
      cnt2++;
    }
  }
  if(u.at(0)==u.at(n-1)) cout << cnt1 + (cnt2-cnt1)*(k-1) << endl;
  else cout << cnt1 * k << endl;
  return 0;
}