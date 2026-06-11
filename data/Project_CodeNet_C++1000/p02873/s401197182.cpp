#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void printv(vector<ll> v) {
  for (ll i : v)
    cout << i << endl;
}

int main() {
  string s;
  cin >> s;
  ll n = s.size() + 1;
  // ll ans = 0;
  vector<ll> a(n, 0);
  rep(i, s.size()) {
    if ((s[i] == '<') && !(a[i] < a[i + 1]))
      a[i + 1] = a[i] + 1;
  }
  for (int i = s.size() - 1; i >= 0; i--) {
    if ((s[i] == '>') && !(a[i] > a[i + 1]))
      a[i] = a[i + 1] + 1;
  }
	ll ans=0;
	rep(i,s.size()+1) ans+=a[i];
	cout<<ans<<endl;
}
