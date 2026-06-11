#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(void){
  int n, k;
  cin >> n >> k;

  vector<ll> s(n+1);
  s[0] = 0;
  rep(i, n){
    ll a;
    cin >> a;
    s[i+1] = (s[i] + a - 1) % k;
  }

  map<ll, ll> mp;
  queue<ll> q;
  ll ans = 0;
  rep(j, n+1){
    ans += mp[s[j]];
    mp[s[j]]++;
    q.push(s[j]);
    if(q.size() == k){
      mp[q.front()]--;
      q.pop();
    }
  }

  cout << ans << endl;
  return 0;
}