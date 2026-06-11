#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define vi vector<int>
#define vvi vector<vi>
#define P pair<int, int>
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  ll n;
  cin >> n;
  ll ans = 0;
  FOR(i, 1, n) { ans += (n - 1) / i; }
  cout << ans << endl;
}