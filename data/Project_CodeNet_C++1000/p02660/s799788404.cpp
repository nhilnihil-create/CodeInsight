#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define mod 1000000007LL
#define INF 1000000011
#define INFLL 1000000000000000011LL
#define endl '\n'
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long>
#define vc vector<char>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pil pair<int, long long>
#define pli pair<long long, int>
#define pcc pair<char, char>
#define pdd pair<double, double>
#define mp make_pair
#define pb(x) push_back(x)
#define fo(i, a, n) for (i = (a); i < (n); i++)
#define foe(i, a, n) for (i = (a); i <= (n); i++)
// clang-format off
#define vin(a) for (ll i = 0; i < sz(a); i++) { cin >> a[i]; } 
#define vout(a) for (auto x : a) { cout << x << " "; }
#define sws                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0)
// clang-format on
#define pd(x) cout << x
#define sd(x) cin >> x
#define nl cout << endl
#define gcd __gcd
#define all(a) (a).begin(), (a).end()
#define foreach(i, a)                                                          \
  for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define sz(a) (int)((a).size())
// int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
ll maxval = pow(10LL, 6);
vector<bool> isComposite(maxval + 1);
vll primes;

void genPrime() {
  for (ll j = 4; j <= maxval; j += 2)
    isComposite[j] = true;

  for (ll j = 3; j <= maxval; j += 2) {
    for (ll k = j + j; k <= maxval; k += j) {
      isComposite[k] = true;
    }
  }

  for (ll i = 2; i <= maxval; i++) {
    if (!isComposite[i])
      primes.pb(i);
  }
}

void solve() {
  ll m, n;
  ll i, j;
  cin >> n;

  ll ans = 0;

  for (ll p : primes) {
    ll count = 0;
    while (n > 1 && n % p == 0) {
      n /= p;
      count++;
    }

    ll x = 0;

    while ((((x + 1) * (x + 2)) / 2) <= count)
      x++;

    ans += x;
  }

  if (n != 1)
    ans++;

  cout << ans << endl;
}

int main() {
  sws;
  genPrime();
  solve();
  return 0;
}