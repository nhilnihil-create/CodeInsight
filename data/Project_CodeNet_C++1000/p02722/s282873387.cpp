#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define rrep(i, a, b) for (int i = a; i >= (b); i--)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <class T>
inline bool chmin(T& a, T b) {
   if (a > b) {
      a = b;
      return true;
   }
   return false;
}
template <class T>
inline bool chmax(T& a, T b) {
   if (a < b) {
      a = b;
      return true;
   }
   return false;
}
void hr() {
   cerr << "--------------" << endl;
}
const int INF = 1001001001;
const int MOD = 1000000007;
// const int MOD = 998244353;

vector<ll> enumDiv(ll n) {
   vector<ll> res;
   for (ll i = 1; i * i <= n; i++) {
      if (n % i != 0) continue;
      res.push_back(i);
      if (i * i != n) res.push_back(n / i);
   }
   return res;
}
int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   ll n;
   cin >> n;
   int ans = 0;
   for (ll x : enumDiv(n)) {
      if (x == 1) continue;
      ll tmp = n;
      while (tmp % x == 0)
         tmp /= x;
      tmp %= x;
      if (tmp == 1) ans++;
   }
   ans += enumDiv(n - 1).size() - 1;
   cout << ans << endl;
   return 0;
}