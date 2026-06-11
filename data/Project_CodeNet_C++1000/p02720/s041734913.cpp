#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

set<ll> ans;
ll max_v = 3234566667;

int rec(vector<ll> &n) {
  int ei = -1;
  rep(i,0,10) {
    if (n[i] == -1) {ei = i; break;}
  }
  ll k = 1;
  ll l = 0;
  rep(i,0,10) {
    if (n[i] == -1) break;
    l += k*n[i];
    k *= 10;
  }
  if (1 <= l && l <= max_v) {
    ans.insert(l);
  }
  if (ei == -1) return 0;
  rep(i,n[ei-1]-1,n[ei-1]+2) {
    if (i == -1 || i == 10) continue;
    n[ei] = i;
    rec(n);
  }
  n[ei] = -1;
  return 0;
}

int main() {
  vector<ll> n(10,-1);
  rep(i,0,10) {
    n[0] = i;
    rec(n);
  }
  int k;
  cin >> k;
  auto itr = ans.begin();
  rep(i,0,k-1) {
    ++itr;
  }
  cout << *itr << endl;
  return 0;
}
