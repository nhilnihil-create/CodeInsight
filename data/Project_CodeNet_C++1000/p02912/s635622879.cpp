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
  int n,m;
  cin >> n >> m;
  priority_queue<ll> q;
  rep(i,n){
    ll x; cin >> x;
    q.push(x);
  }
  rep(i,m){
    auto p = q.top(); q.pop();
    q.push(p/2);
  }
  ll ans = 0;
  while(!q.empty()){
    auto p = q.top(); q.pop();
    ans += p;
  }

  cout << ans << ln;
  return 0;
}