#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define IFOR(i, m, n) for(ll i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

typedef pair<ll,ll> P;

void no(){
  cout << -1 << endl;
  exit(0);
}

int main(){
  ll n; cin >> n;
  vector<ll> a(n), b(n);
  priority_queue<P, vector<P>,less<P>> pq;
  REP(i,n) cin >> a[i];
  REP(i,n){
    cin >> b[i];
    pq.push({b[i],i});
  }
  ll ans = 0;
  while(!pq.empty()){
    ll i =  pq.top().second;
    pq.pop();
    if(b[i] == a[i]) continue;
    ll step = b[(i+1+n)%n] + b[(i-1+n)%n];
    if(b[i]<step) no();
    if(b[i]>a[i] && (b[i]-a[i])%step == 0){
      ans += (b[i]-a[i])/step;
      b[i] = a[i];
      continue;
    }
    if(b[i]>a[i]){
      ans += b[i]/step;
      b[i] %= step;
    }
    if(b[i]<a[i]) no();
    pq.push({b[i],i});
  }
  cout << ans << endl;
}

