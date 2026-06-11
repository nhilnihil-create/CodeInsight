#include <bits/stdc++.h>
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,b)for(int i=(int)(a);(i)<(int)(b);i++)

typedef unsigned long long ull;
typedef long long ll;

const int INF = 1001001001;
const ll MOD = 1e9 + 7;

using namespace std;
using P = pair<int,int>;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll c, ll d) { return c / gcd(c, d) * d; }

int main() {
  ll n; cin >> n;
  ll a[n]; ll s[n+1] = {0};
  rep(i, n) {
      cin >> a[i];
      s[i+1] = s[i] + a[i];
  }

  ll min_diff = 20000000000;
  rep(i, n) {
      if (s[n]-s[i] == s[i]) 
      {
          cout << 0 << endl;
          return 0;
      }
      min_diff = min(min_diff, abs(s[n] - s[i] - s[i]));
  }
  cout << min_diff << endl;
  
  return 0;
}