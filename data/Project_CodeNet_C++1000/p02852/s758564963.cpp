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
  ll n, m, k;
  in2(n, m);
  string s, t, u;
  in(t);
  s = "";
  rep(i, n + 1){
    u = t[n - i];
    s += u;
  }
  vector<ll> c;
  k = 0;
  while(k < n){
    if(k + m >= n){
      c.pb(n - k);
      k = n;
    }
    else{
      rep(i, m){
        if(s[k + m - i] == '0'){
          k = k + m - i;
          c.pb(m - i);
          break;
        }
        if(i == m - 1){
          out(-1);
          memi;
          return 0;
        }
      }
    }
  }
  rep(i, c.size()){
    out(c[c.size() - i - 1]);
    hina;
  }
  memi;
}
