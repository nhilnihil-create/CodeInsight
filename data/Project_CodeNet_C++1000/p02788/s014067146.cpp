#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
  ll n, d, a; cin >> n >> d >> a;
  vector<pair<ll, ll>> v(n);
  rep(i, n) cin >> v[i].first >> v[i].second;
  sort(v.begin(), v.end());
  ll ans = 0, sum = 0;
  queue<pair<ll, ll>> q;
  rep(i, n){
    ll x = v[i].first, h = v[i].second;
    while(q.size() > 0 && q.front().first < x){
      sum -= q.front().second;
      q.pop();
    }
    ll right = x + 2 * d;
    ll remain = max(0LL, h - sum);
    if(remain % a != 0){
      remain += (a - (remain % a));
    }
    sum += remain;
    ans += remain / a;
    if(remain != 0 && right <= v[n - 1].first) q.push(make_pair(right, remain));
  }
  cout << ans << endl;
  return 0;
}
