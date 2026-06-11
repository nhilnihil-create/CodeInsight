#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  int n;
  string s;
  cin >> n >> s;

  vector<int> a(n);
  rep(i, n) {
    if(s[i] == 'R')
      a[i] = 0;
    if(s[i] == 'G')
      a[i] = 1;
    if(s[i] == 'B')
      a[i] = 2;
  }

  vector<ll> cnt(3);
  rep(i, n) cnt[a[i]]++;

  ll ans = 1;
  rep(i, 3) ans *= cnt[i];

  rep(j, n) rep(i, j) {
    int k = j + (j - i);
    if(k < n) {
      if(a[i] == a[j])
        continue;
      if(a[i] == a[k])
        continue;
      if(a[k] == a[j])
        continue;
      ans--;
    }
  }

  cout << ans;
}
