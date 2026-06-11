//verma_ankit484

#include<bits/stdc++.h>

typedef long long ll;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define pb push_back
const ll mod = (ll) 1e9+7;

using namespace std;

ll n, k;

vector<ll> vc;

ll dp[305][305][305];

ll rec(ll idx, ll kk, ll lst) {
  if (kk > k) return (ll) 1e12;
  if (idx == n) return 0;
  ll &ans = dp[idx][kk][lst];
  if (ans != -1) return ans;
  ans = (ll) 1e13;
  ans = min(ans, rec(idx+1, kk+1, lst));
  if (vc[lst] < vc[idx]) {
    ans = min(ans, vc[idx]-vc[lst]+rec(idx+1, kk, idx));
  } else ans = min(ans, rec(idx+1, kk, idx));
  return ans;
}

int main() {
  IOS
  #ifdef AV
  freopen("int.txt", "r", stdin);
  #endif
  cin >> n >> k;
  vc.resize(n);
  for (ll i = 0; i < n; i++) {
    cin >> vc[i];
  }
  vc.pb(0);
  memset(dp, -1, sizeof(dp));
  cout << rec(0, 0, n) << endl;
  return 0;
}
