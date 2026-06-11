#include <bits/stdc++.h>
using namespace std; 
using ll = long long;

int main(){
  ll n, k; cin >> n >> k;
  vector<ll> a(n), f(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> f[i];
  ll mn = 0;
  for(int i = 0; i < n; i++){
    mn = max(mn, a[i] * f[i]);
  }
  sort(a.begin(), a.end());
  sort(f.begin(), f.end(), greater<ll>());
  ll ng = -1, ok = mn;
  while(abs(ok - ng) > 1){
    ll mid = (ok + ng) / 2;
    ll cnt = 0;
    for(int i = 0; i < n; i++){
      ll tmp = a[i] - mid / f[i];
      if(tmp < 0) continue;
      cnt += tmp;
    }
    if(cnt <= k) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}