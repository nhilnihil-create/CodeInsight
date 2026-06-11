#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, a, n) for(ll i = a; i < (ll)(n); i++)
#define memi cout << endl
#define kono(n) cout << fixed << setprecision(n)
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define hina cout << ' '
#define in(n) cin >> n
#define in2(n, m) cin >> n >> m
#define in3(n, m, l) cin >> n >> m >> l
#define out(n) cout << n
const ll mei = (ll)1e9 + 7;

int main(){
  ll a, b, c, d, e, f, s;
  in(s);
  a = 0;
  b = 0;
  c = 1000000000;
  d = 1;
  f = (s + 999999999) / 1000000000;
  e = 1000000000 * f - s;
  out(a);
  hina;
  out(b);
  hina;
  out(c);
  hina;
  out(d);
  hina;
  out(e);
  hina;
  out(f);
  memi;
}