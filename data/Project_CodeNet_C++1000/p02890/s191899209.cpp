#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T> bool chmax(T &a, const T &b){ if(a < b){ a = b; return 1; } else return 0; }

int main(){
  ll n;
  cin >> n;
  vector<ll> b(n + 1), ans(n + 1);
  unordered_map<ll, ll> m;
  for(ll i = 0; i < n; i++){
    ll a;
    cin >> a;
    b[++m[a]]++;
  }
  for(ll i = 1; i < n; i++) b[i + 1] += b[i];
  for(ll i = 1; i <= n; i++) chmax(ans[b[i] / i], i);
  for(ll i = n; i > 0; i--) chmax(ans[i - 1], ans[i]);
  for(ll i = 1; i <= n; i++) cout << ans[i] << endl;
}
