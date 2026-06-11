#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=200010;
const ll mod=1e9+7;


int main(){
  ll m;
  cin >> m;
  ll k=0, d=0;
  
  rep(i,m){
    ll a,b; cin >> a >> b;
    k += b;
    d += a*b;
  }
  
  ll ans = (d-1)/9 + k-1;
  cout << ans << endl;
  return 0;
}