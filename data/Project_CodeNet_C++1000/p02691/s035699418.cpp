#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  for(int i=0; i<n; i++){
    ll tmp;
    cin >> tmp;
    b[i] = i+1 - tmp;
    a[i] = tmp + i+1;
  }
  ll ans = 0;
  sort(b.begin(),b.end());
  /*
  for(int i=0; i<n; i++){
    cout << b[i].first << " " << b[i].second << endl;
  }*/
  for(int i=0; i<n; i++){
    auto l = lower_bound(b.begin(),b.end(),a[i]);
    auto r = upper_bound(b.begin(),b.end(),a[i]);
    ans += r-l;
  }
  cout << ans << endl;
}