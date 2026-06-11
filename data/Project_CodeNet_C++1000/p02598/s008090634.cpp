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
  ll n, k;
  cin >> n >> k;
  vi d(n);
  int max_a = 0;
  REP(i, n) {
    cin >> d[i];
    chmax(max_a, d[i]);
  }
  int l = 0;
  int r = max_a;
  while (r - l > 1) {
    int x = (l + r) / 2;
    int cnt = 0;
    for (auto a : d) {
      cnt += (a - 1) / x;
    }
    cnt <= k ? r = x : l = x;
  }
  cout << r << endl;
}