#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(n) n.begin(),n.end()
#define yn(x) cout << (x ? "Yes":"No") << endl;

int main() {
  ll n;
  cin >> n;
  vector<ll>a(n);
  ll sum = 0,sum1 = 0;
  rep(i,n) {
    cin >> a[i];
    sum += a[i];
  }
  ll ans = sum;
  rep(i,n-1){
    sum1 += a[i];
    ans = min(ans,abs(sum1-(sum-sum1)));
  }
  cout << ans << endl;
}
