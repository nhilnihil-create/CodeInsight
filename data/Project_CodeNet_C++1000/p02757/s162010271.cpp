#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
#define MOD (ll)1000000007
#define PI 3.14159265359
//#define P pair<ll, ll>
//printf("%.10f\n")
//cout << fixed << setprecision(10);
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;

int
main()
{
  int N, P; cin >> N >> P;
  string s; cin >> s;
  map<ll, ll> m;
  ll digit = 1;
  ll current = 0;
  ll ans = 0;
  m[0] += 1;

  if(P == 2 || P == 5){
    ll inc = 0;
    rep(i, 0, N){
     if((s[i] - '0') % P == 0) ans += i + 1;
    }
    cout << ans << endl;
    return 0;
  }

  for(ll i = N - 1; i >= 0; --i){
    current = (digit* (s[i] - '0') + current) % P;
    digit *= 10; digit %= P;
    m[current] += 1;
  }

  for(auto x: m){
    ans += x.second * (x.second - 1) / 2;
  }

  cout << ans << endl;

}
