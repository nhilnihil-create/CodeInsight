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
constexpr char ln = '\n';

const int mx=100010;
const ll mod=1e9+7;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  ll odd = 0;
  rep(i,n){
    cin >> a[i];
    odd ^= a[i];
  }
  rep(i,n){
    a[i] &= ~odd;
  }

  vector<ll> base;
  rep(i,n){
    ll tmp = a[i];
    for(auto it:base){
      tmp = min(tmp, (tmp^it));
    }
    if(tmp!=0){ base.emplace_back(tmp); }
  }
  ll even = 0;
  for(auto it:base){
    even = max(even, (even^it));
  }

  ll ans = odd + even*2;
  cout << ans << ln;
  return 0;
}