#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD = 1e9+7;

#define vec     vector<int>
#define vecll   vector<ll>
#define vec2    vector<vector<int>>
#define vec2ll  vector<vector<ll>>
#define vpair   vector<pair<int, int>>
#define vpairll vector<pair<ll, ll>>

#define rep(i,n)         for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n)       for(ll i=(ll)m; i<(ll)n; i++)
#define arr(var, n)      vec var(n); rep(i,n){cin >> var[i];}
#define arrll(var, n)    vecll var(n); rep(i,n){cin >> var[i];}
#define all(var)         (var).begin(), (var).end()
#define sortall(var)     sort(all(var))
#define mpair(v1, v2)    make_pair(v1, v2)
#define pb(var)          push_back(var)
#define prt(var)         cout << var << "\n"
#define scn(var)         cin >> var;
#define pYes()           prt("Yes")
#define pNo()            prt("No")
#define prtd(n, var)     cout << fixed << setprecision(n) << var << "\n"
#define prt2(v1, v2)     cout << v1 << " " << v2 << "\n"
#define prt3(v1, v2, v3) cout << v1 << " " << v2 << " " << v3 << "\n"
#define prtall(var)      rep(i,var.size()){cout << var[i] << " ";} cout << "\n"
//----------------------------------------------------------------
ll gcd(ll a, ll b){ return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){ return a/gcd(a,b)*b;}

ll div2(ll x){
  ll num=0;
  while(x%2==0){
    x /= 2;
    num++;
  }
  return num;
}

int main(void) {
  ll n, m;
  cin >> n >> m;
  arrll(a,n);
  rep(i,n){
    a[i] /= 2;
  }

  ll k=div2(a[0]);
  rep(i,n){
    if(k!=div2(a[i])){
      prt(0); return 0;
    }
    a[i] >>= k;
  }
  m >>= k;

  ll l=1;
  rep(i,n){
    l = lcm(a[i], l);
    if(l > m){
      prt(0); return 0;
    }
  }
  prt(1+(m-l)/(2*l));
}
