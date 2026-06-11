#include <bits/stdc++.h>

#define all(A) begin(A), end(A)
#define rall(A) rbegin(A), rend(A)
#define sz(A) int(A.size())
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int main () {
  ios::sync_with_stdio(false); cin.tie(0);
  ll n, k;
  cin >> n >> k;
  const ll MOD = 1e9 + 7;
  vector <ll> arr(n);
  const int MX = 2010;
  vector <int> cnt(MX, 0);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    cnt[arr[i]]++;
  }
  vector <int> vis(MX, 0);
  ll ans = 0;
  for (int j = 0; j < n; j++) {
    ll x = 0;
    ll gt = 0;
    for (int i = arr[j] + 1; i < MX; i++) {
      x += vis[i];
      gt += cnt[i];
    }
    ll add1 = (k * x) % MOD;
    ll add2 = ((k - 1) * k / 2) % MOD;
    ll add = (add1 + gt * add2) % MOD;
    ans = (ans + add) % MOD;
    vis[arr[j]]++;
  }
  cout << ans << '\n';
  return (0);
}