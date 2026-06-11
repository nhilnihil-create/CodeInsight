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
 
#define bit(n,k) ((n>>k)&1) //*n no k bit me 1 or 0*/

const int mx=100010;
const ll mod=1e9+7;


int main(){  
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  ll sum = 0;
  rep(i,n){
    cin >> a[i];
    sum += a[i];
  }
  priority_queue<ll> q;
  for(int i=1; i<ceil(sqrt(sum)); i++)if(sum%i==0){
    q.push(i);
    q.push(sum/i);
  }
  q.push(0); q.push(sum);

  ll ans = 1;
  while(!q.empty()){
    ll p = q.top(); q.pop();
    ll cnt = longinf;
    vector<ll> calc(n);
    rep(i,n) calc[i] = a[i]%p;
    sort(calc.begin(),calc.end());

    ll pl = 0;
    rep(i,n) pl += p - calc[i];
    ll mi = 0;
    rep(i,n){
      mi += calc[i];
      pl -= p-calc[i];
      cnt = min(cnt, max(pl,mi));
    }
    
    if(cnt<=k){
      ans = p;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}