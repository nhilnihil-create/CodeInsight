#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll n, p; cin >> n >> p;
  string s; cin >> s;
  ll r=0, ans=0, acc=1;
  if (p == 2) {
    for (int i = 0; i < n; i++) {
      if ((s[i]-'0')&1^1) ans+=i+1;
    }
    cout << ans;
    return 0;
  }
  if (p == 5) {
    for (int i = 0; i < n; i++) {
      if (s[i] == '0' || s[i] == '5')
        ans+=i+1;
    }
    cout << ans;
    return 0;
  }
  map<ll, ll> mp;
  mp[0] = 1;
  for (int i = n-1; ~i; i--, acc = ((acc*10)%p + p)%p) {
    r = (((acc*(s[i]-'0') + r) % p) + p) % p;
    if (mp.find(r) != mp.end())
      ans+=mp[r];
    else
      mp.insert({r, 0});
    mp[r]++;
  }
  cout << ans;
}
