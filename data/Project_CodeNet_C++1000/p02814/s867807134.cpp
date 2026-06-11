#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n, m;
  cin >> n >> m;
  vector < ll > a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
    a[i] /= 2;
  }
  ll lcm = 1;
  for(int i = 0; i < n; i++){
    lcm = (a[i] * lcm) / __gcd(a[i], lcm);
  }

  bool ok = true;
  for(int i = 0; i < n; i++){
    ll b = lcm / a[i];
    if(b % 2 == 0) ok = false;
  }

  if(ok){
    ll lo = 0, hi = 1e9, k = 0;
    while(lo <= hi && lcm <= m){
      ll mid = (hi - lo) / 2 + lo;
      if((2 * mid - 1) * lcm <= m){
        k = max(k, mid);
        lo = mid + 1;
      }else hi = mid - 1;
    }

    cout << k << endl;
  }else{
    cout << 0 << '\n';
  }
}
