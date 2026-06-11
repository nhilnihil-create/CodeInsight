#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<int,int>  pint;
typedef pair<ll,ll>    pll;
typedef vector<int>    vint;
typedef vector<ll>     vll;
typedef vector<string> vstr;
typedef vector<pint>   vpint;
typedef vector<pll>    vpll;

#define vint2(v,n,m,init) vector<vector<int>> v(n, vector<int>(m, init))
#define vll2(v,n,m,init)  vector<vector<ll>>  v(n, vector<ll>(m, init))

#define rep(i,n)         for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n)       for(ll i=(ll)m; i<(ll)n; i++)
#define arr(var, n)      vint var(n); rep(i,n){cin >> var[i];}
#define arrll(var, n)    vll var(n); rep(i,n){cin >> var[i];}
#define arrst(var, n)    vstr var(n); rep(i,n){cin >> var[i];}
#define ALL(var)         (var).begin(), (var).end()
#define sortall(var)     sort(ALL(var))
#define uniqueall(v)     v.erase(unique(v.begin(), v.end()), v.end());

#define prt(var)         cout << (var) << "\n"
#define prt2(v1, v2)     cout << (v1) << " " << (v2) << "\n"
#define prt3(v1, v2, v3) cout << (v1) << " " << (v2) << " " << (v3) << "\n"
#define prtd(n, var)     cout << fixed << setprecision(n) << (var) << "\n"
#define prtfill(n, var)  cout << setw(n) << setfill('0') << (var);
#define prtall(v)        rep(i,v.size()){cout<<v[i]<<(i!=v.size()-1?" ":"\n");}
template <typename T>
bool chmax(T &a, const T& b){if(a<b){a=b; return true;} return false;}
template <typename T>
bool chmin(T &a, const T& b){if(a>b){a=b; return true;} return false;}
//-----------------------------------------------------------------------------

int main(void){
  int n;
  cin >> n;
  arrll(a,n+1);

  ll sum=0;
  rep(i,n+1){
    sum += a[i];
  }

  if(a[0]>1){
    prt(-1);
    return 0;
  }
  ll b = 1-a[0];
  ll ans = a[0] + b;
  sum -= a[0];
  REP(i,1,n+1){
    if(b*2<a[i]){
      prt(-1);
      return 0;
    }
    sum -= a[i];
    b = min(sum, 2*b-a[i]);
    ans += a[i]+b;
  }

  prt(ans);
}
