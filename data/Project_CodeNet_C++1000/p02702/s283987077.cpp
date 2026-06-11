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
  string s; cin >> s;
  int N = s.size();
  map<ll, ll> mods;
  mods[0] += 1;
  ll digit = 1;
  ll current = 0;
  for(int i = N - 1; i >= 0; --i){
    current = (current + (s[i] - '0') * digit) % 2019;
    digit *= 10; digit %= 2019;
    mods[current] += 1;
  }

  ll ans = 0;
  for(auto x: mods){
    ans += (x.second * (x.second - 1)) / 2;
  }

  cout << ans << endl;

}
