#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(ll i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
constexpr char ln = '\n';

const int mx=200010;
const ll mod=1e9+7;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n),b(n);
  priority_queue<pair<ll,int>> q;
  rep(i,n){
    cin >> a[i];
  }
  rep(i,n){
    cin >> b[i];
    q.push({b[i],i});
  }
  ll ans = 0;
  while(!q.empty()){
    auto p = q.top(); q.pop();
    int pl = p.S-1;
    if(pl<0) pl+=n;
    int pr = p.S+1;
    if(n<=pr) pr-=n;
    ll cnt = (b[p.S]-a[p.S])/(b[pl]+b[pr]);
    b[p.S] -= (b[pl]+b[pr])*cnt;
    ans += cnt;
    if(b[p.S]!=a[p.S] && cnt > 0){
      q.push({b[p.S],p.S});
    }    
  }

  if(a==b){
    cout << ans << ln;
  } else {
    cout << -1 << ln; return 0;
  }
  return 0;
}