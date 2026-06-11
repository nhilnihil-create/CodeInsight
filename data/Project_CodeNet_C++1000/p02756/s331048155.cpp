#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s; cin >> s;
  deque<char> dq;
  rep(i,s.size()) dq.push_back(s[i]);
  int q; cin >> q;
  int rev;
  rep(i,q) {
    int qi; cin >> qi;
    if (qi == 1) rev++;
    else {
      int f; cin >> f;
      char c; cin >> c;
      if (f == 1) {
        if (rev%2 == 0) dq.push_front(c); 
        else dq.push_back(c);
      }
      else { 
        if (rev%2 == 0) dq.push_back(c); 
        else dq.push_front(c);
      }
    }
  }
  while(!dq.empty()) {
    if (rev%2 == 0) {
      cout << dq.front();
      dq.pop_front();
    } else {
      cout << dq.back();
      dq.pop_back();
    }
  }
  cout << endl;
  return 0;
}