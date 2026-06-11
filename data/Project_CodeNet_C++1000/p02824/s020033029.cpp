#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
  ll n,m,v,p;
  cin >> n >> m >> v >> p;
  vl a(n);
  rep(i,n){
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  auto check = [&](ll M) -> bool {
    bool ok=false;
    bool sub=true;
    ll s=0;
    //a[M]で条件満たすの?
    FOR(i,M+1,n-p+1){
      if(a[M]+m-a[i]>=0){
        s +=(a[M]+m-a[i]);
      }
      else
        sub=false;
    }
    if((M+1)*m+s>=m*(v-p+1)){
      ok=true;
    }
    return ok && sub;
  };
  
  ll ok = n - 1, ng = -1;
  while(abs(ok - ng) > 1){
    ll cen = (ok + ng) / 2;
    (check(cen) ? ok : ng) = cen;
  }
  
  cout << n - ok << endl;
}
