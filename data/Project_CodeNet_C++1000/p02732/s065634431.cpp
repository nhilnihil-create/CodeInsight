#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll com(ll n){
  ll res = n*(n-1)/2;
  return res;
}

int main(void){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> cnt(n);
  rep(i,n){
    cin >> a[i];
    cnt[a[i]]++;
  }
  ll tot = 0;
  rep(i,n+1) tot += com(cnt[i]);
  rep(i,n){
    ll ans = tot;
    ans -= com(cnt[a[i]]);
    ans += com(cnt[a[i]]-1);
    cout << ans << endl;
  }
  return 0;
}