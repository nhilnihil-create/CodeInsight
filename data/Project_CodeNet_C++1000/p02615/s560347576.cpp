#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  sort(a.rbegin(),a.rend());

  ll ans = 0;
  int res = n-1;
  rep(i,n){
    if(i == 0){
      ans += a[0];
      res--;
      continue;
    }
    else if(res >= 2) {
      ans += a[i]*2;
      res -= 2;
      continue;
    }
    else if(res == 1) {
      ans += a[i];
      res -= 1;
      continue;
    }
    if(res==0) break;
  }
  cout << ans << endl;
}
