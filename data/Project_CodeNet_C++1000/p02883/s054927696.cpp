#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll mod = 1e9 + 7;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n, k;
  cin >> n >> k;
  vector < ll > a(n), f(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> f[i];

  sort(a.begin(), a.end());
  sort(f.begin(), f.end());

  ll lo = 0, hi = 1e12;
  ll ans = LLONG_MAX;
  while(lo <= hi){
    ll mid = (hi - lo) / 2 + lo;
    ll cnt = 0;
    for(int i = 0; i < n; i++){
      cnt += max((ll)0, a[i] - (mid / f[n - i - 1]));
    }
    if(cnt <= k){
      hi = mid - 1;
      ans = min(ans, mid);
    }
    else lo = mid + 1;
  }

  cout << ans << endl;
}
