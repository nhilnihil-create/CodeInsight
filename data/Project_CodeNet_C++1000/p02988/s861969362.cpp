#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  ll n; cin>>n;
  ll a[n]; rep(i, n) cin>>a[i];
  ll cnt=0;
  for(ll i=1; i<n-1; i++){
    if(min(min(a[i-1], a[i]), a[i+1])!=a[i]&&
        max(max(a[i-1], a[i]), a[i+1])!=a[i]) cnt++;
  }
  cout << cnt;
}