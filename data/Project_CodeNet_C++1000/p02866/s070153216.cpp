#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;

int main() {
  ll N;
  cin >> N;
  vector<ll> D(N);
  for (ll i=0; i<N; i++) cin >> D[i];
  if (D[0]!=0) cout << 0 << endl;
  else {
    map<ll, ll> dict; // 各数字の登場回数
    for (ll i=0; i<N; i++) {
      if (dict.count(D[i])) dict[D[i]]++;
      else dict[D[i]] = 1;
    }
    ll res = 1;
    for (ll i=1; i<N; i++) {
      res *= dict[D[i]-1];
      res %= Mod;
    }
    cout << res << endl;
  }
}