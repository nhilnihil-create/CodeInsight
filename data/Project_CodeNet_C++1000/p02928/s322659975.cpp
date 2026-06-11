#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int MOD=1000000007;


int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  ll ans=0;
  rep(i,n-1) {
    for(int j=i+1; j<n; j++) {
      if(a[i]>a[j]) ans+=(ll)(k+1)*k/2%MOD;
      ans%=MOD;
    }
  }
  rep(i,n) {
    for(int j=0; j<i; j++) {
      if(a[i]>a[j]) ans+=(ll)k*(k-1)/2%MOD;
      ans%=MOD;
    }
  }
  cout << ans << endl;
  return 0;
}
