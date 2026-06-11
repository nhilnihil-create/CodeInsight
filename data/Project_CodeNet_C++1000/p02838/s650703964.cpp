#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define mod 1000000007

int main() {
  ll n;
  cin >> n;
  vll a(n);
  rep(i,n) cin >> a[i];
  vll cnt(60);
  rep(i,n)rep(j,60) if(a[i]>>j&1LL) cnt[j]++;
  ll ans = 0LL;
  rep(i,60) {
    ll tmp = cnt[i]*(n-cnt[i]);
    rep(j,i) {
      tmp *= 2LL;
      tmp %= mod;
    }
    ans += tmp;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}