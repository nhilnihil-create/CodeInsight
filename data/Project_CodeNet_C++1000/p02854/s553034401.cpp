#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;
const int INF = 1001001001;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
  }
  ll sum = 0;
  rep(i, n) {
    sum += a[i];
  }
  ll ans = LLONG_MAX;
  ll l = 0;
  for(int i = 0; i < n; ++i) {
    l += a[i];
    ll r = sum - l;
    ans = min(ans, abs(l - r));
  }
  cout << ans << endl;
}