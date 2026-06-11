#include<bits/stdc++.h>
#define rep(i,f,n) for(ll i=(f); (i) < (n); i++)
#define repe(i,f,n) for(ll i=(f); (i) <= (n); i++)
using namespace std;
using ll = long long;
#define MOD (ll)1000000007
#define PI 3.14159265359
#define debug(x) cout<<#x<<" :: "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<"\n";
//#define P pair<ll, ll>
//printf("%.10f\n")
//cout << fixed << setprecision(10);
template<class T> inline bool chmax(T& a, T b){if (a < b) { a = b; return true; } return false;}
template<class T> inline bool chmin(T& a, T b){if (a > b) { a = b; return true; } return false;}
ll INF = 1e+18;
int iINF = 1e9;

ll 
power(ll x, ll y, ll m = MOD) 
{ 
    if (y == 0) 
        return 1; 
    ll p = power(x, y/2ll, m) % m; 
    p = (p * p) % m; 
    return (y%2 == 0)? p : (x * p) % m; 
}

int
main()
{

  int N, K; cin >> N >> K;
  vector<ll> divises(K + 1);
  ll ans = 0;
  for(ll i = K; i >= 1; --i){
    ll num = K / i;
    ll add = power(num, N);
    if(i <= K / 2){
      ll tmp = i + i;
      while(tmp <= K){
        add =(add - divises[tmp] + MOD) % MOD;
        tmp += i;
      }
    }
    divises[i] = add;
    ans = (ans + divises[i] * i) % MOD;
  }
  ans = (ans + MOD) % MOD;
  cout << ans << endl;

}
