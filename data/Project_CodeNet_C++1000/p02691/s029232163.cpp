#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repc(i, a, b) for(int i = a; i <= (int)(b); i++)
#define ll long long
#define vec vector
#define ft first
#define sd second
#define all(vec) vec.begin(), vec.end()
typedef pair<int, int> P;
const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main() {
  int n;
  cin >> n;
  vec<int> a(n);
  rep(i, n) cin >> a[i];
  map<int, int> mp;
  ll ans = 0;
  rep(i, n) {
    int sa = i - a[i];
    ans += mp[sa];
    int wa = a[i] + i;
    mp[wa]++;
  }
  cout << ans << endl;
  return 0;
}