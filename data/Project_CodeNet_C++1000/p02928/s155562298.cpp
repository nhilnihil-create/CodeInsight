#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;



int main() {
  ll n, k; cin >> n >> k;
  Vl a(n);
  rep(i, 0, n) cin >> a[i];
  ll cnt1 = 0; // 数列内
  ll cnt2 = 0; // 数列間
  rep(i, 0, n-1) rep(j, i+1, n){
    if(a[i] > a[j]) cnt1++;
  }
  rep(i, 0, n) rep(j, 0, n){
    if(a[i] > a[j]) cnt2++;
  }
  ll ans = 0;
  ans += cnt1*k%MOD;
  ans += cnt2*(((k-1)*k/2)%MOD)%MOD;
  ans %= MOD;

  cout << ans << endl;

  return 0;
}
