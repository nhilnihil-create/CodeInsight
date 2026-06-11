#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector <int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;
const int mod = 1e9 + 7;
const ll inf = 3e18 + 5;
int add(int a, int b) { return (a += b) < mod ? a : a - mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }
int sub(int a, int b) { return (a -= b) < 0 ? a + mod : a; }
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
 
  int n, p;
  cin >> n >> p;
  string s;
  cin >> s;
  reverse(all(s));
  vi v(n);
  for(int i = 0; i < n; i++) {
    v[i] = s[i] - '0';
  }
  if(p == 2 || p == 5) {
    ll res = 0;
    for(int i = 0; i < n; i++) {
      if(v[i] % p == 0) {
        res += n - i;
      } 
    }
    cout << res;
    return 0;
  }
  vi pwr(n);
  int pw = 1;
  for(int i = 0; i < n; i++) {
    pwr[i] = pw;
    pw *= 10;
    pw %= p;
  }
  vi cnt(p);
  int x = 0;
  for(int i = 0; i < n; i++) {
    x += pwr[i] * v[i];
    x %= p;
    cnt[x]++;
  }
  ll res = 0;
  cnt[0]++;
  for(int i = 0; i < p; i++) {
    res += 1ll * cnt[i] * (cnt[i] - 1) / 2;
  }
  cout << res;
}