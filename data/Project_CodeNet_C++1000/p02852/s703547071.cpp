#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M;
string s;
ll f[100001];

//x-M以上でs=0なる最小の値を出力
ll ms(ll x) {
  if (x-M > 0) {
    ll ub = x+1; ll lb = x-M-1;
    while (ub-lb > 1) {
      ll mid = (ub+lb)/2;
      ((f[mid] > f[x-M-1])? ub:lb) = mid;
    }
    return ub;
  } else {
    return 0;
  }
}

int main() {
  cin >> N >> M;
  cin >> s;
  f[0] = 0;
  for (ll i = 1; i < N+1; i++) {
    if (s[i] == '0') {f[i] = f[i-1]+1;}
    if (s[i] == '1') {f[i] = f[i-1];}
  }
  //cout << ms(1) << endl;
  //cout << f[6] << f[7] << f[8] << f[9] << f[10] << endl;
  
  vector<ll> v;
  ll pos = N;
  while (pos > 0) {
    v.push_back(pos - ms(pos));
    if (pos == ms(pos)) {cout << -1 << endl; return 0;}
    pos = ms(pos);
  }
  for (ll i = v.size()-1; i >= 0; i--) {
    cout << v[i] << " ";
  }
  cout << endl;
}