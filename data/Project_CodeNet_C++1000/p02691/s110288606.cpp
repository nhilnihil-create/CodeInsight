#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    map<ll,int> mp;
    ll ans = 0;
    rep(i,n) {
      ll js = i-a[i];
      ll is = i+a[i];
      if (mp.count(js)) ans += mp[js];
      mp[is]++;
    }
    cout << ans << endl;
    return 0;
}