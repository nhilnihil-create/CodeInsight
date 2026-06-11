#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
const ll mod = 1000000007;
const ll INF = 9223372036854775807;
#define Sort(a) sort(a.begin(), a.end())
#define Reverse(a) reverse(a.begin(), a.end())
#define Pi acos(-1)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  string s;
  cin >> s;
  deque <char> u;
  rep(i,s.size()) {
    u.push_back(s[i]);
  }
  ll n;
  cin >> n;
  ll a = 0;
  rep(i,n) {
    ll t;
    cin >> t;
    if (a%2 == 0) {
      if (t == 1) {
        a++;
      }
      else {
        ll f;
        char c;
        cin >> f >> c;
        if (f == 1) {
          u.push_front(c);
        }
        else {
          u.push_back(c);
        }
      }
    }
    else if (a%2 == 1) {
      if (t == 1) {
        a++;
      }
      else {
        ll f;
        char c;
        cin >> f >> c;
        if (f == 2) {
          u.push_front(c);
        }
        else {
          u.push_back(c);
        }
      }
    }
  }
  if (a%2 == 1) Reverse(u);
  rep(i,u.size()) cout << u[i];
  cout << '\n';
}