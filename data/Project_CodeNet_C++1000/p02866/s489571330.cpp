#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,j,n) for(int i=j;i<n;++i)
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(), i.rend()
#define INF 1e9
#define LINF 1e18
const int mod = 998244353;
 
typedef long long i64;
typedef pair<int, int> pi;
 
template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;
 
i64 gcd(i64 n, i64 m) {return (m == 0? n : gcd(m, n % m));}
i64 lcm(i64 n, i64 m) {return (n / gcd(n, m) * m);}
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

i64 pow(i64 x, i64 n, i64 mod) {
  i64 ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= mod;
    (x *= x) %= mod;
    n >>= 1;
  }
  return ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vt<int> d(n);
  rep(i, 0, n) cin >> d[i];

  vt<i64> cnt(n, 0);
  rep(i, 0, n) cnt[d[i]]++;
  if(cnt[0] != 1 || d[0] != 0) return cout << 0 << endl, 0;
  
  i64 ans = 1;
  rep(i, 1, n) {
    if(cnt[i] == 0) continue;
    if(cnt[i - 1] <= 0) return cout << 0 << endl, 0;
    ans *= pow(cnt[i - 1], cnt[i], mod);
    ans %= mod;
  }
  cout << ans << endl;
}