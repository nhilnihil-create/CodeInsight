#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long mod = 1000000007LL;

int main() {
  ll n, k;
  cin >> n >> k;
  vll a(n);
  rep(i,n) cin >> a[i];
  ll ng = 0;
  ll ok = 1000000000LL;
  while(ok-ng>1) {
    ll m = (ok+ng)/2;
    ll cnt = 0LL;
    rep(i,n) cnt += (ceil)((double)a[i]/(double)m)-1;
    if(cnt>k) ng = m;
    else ok = m;
  }
  cout << ok << endl;
  return 0;
}