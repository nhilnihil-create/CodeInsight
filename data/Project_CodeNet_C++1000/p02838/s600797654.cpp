#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
#define MOD (ll)1000000007
#define PI 3.14159265359
#define P pair<ll, ll>
//printf("%.10f\n")
//cout << fixed << setprecision(10);
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;

int
main()
{
  int N; cin >> N;
  vector<ll> arr(N);
  rep(i, 0, N) cin >> arr[i];
  ll ans = 0;

  for(int i = 0; i < 60; i++){
    ll one = 0;
    ll zero = 0;
    rep(k, 0, N){
      if((arr[k] & (1LL << i))) ++one;
      else ++zero;
    }
    ll add = (one * zero) % MOD;
    repe(k, 1, i){
      add = (add * 2) % MOD;
    }
    //ll add = ((one * zero) * ((ll)pow(2, i)) % MOD) % MOD;
    ans += add;
    ans %= MOD;
  }
  cout << ans << endl;
}
