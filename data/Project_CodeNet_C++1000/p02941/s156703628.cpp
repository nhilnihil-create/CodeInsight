#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef long double ld;
typedef vector<ld> vd;
typedef bool bl;
typedef vector<bl> vb;
typedef vector<vl> mt;
typedef unordered_map<ll,unordered_map<ll,ll>> graph;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef vector<string> vs;
typedef vector<vs> table;
typedef vector<vl> v2;
typedef vector<v2> v3;
typedef vector<v3> v4;


const ll e5 = 1 << 20;
const ll mod = 1000000007;
const ll e3 = 1 << 13;
const ll INF = 1ll << 50;

ll n;
vl a;
vl b;
ll ans = 0;
ll cnt;

void error(){
  cout << -1 << endl;
  exit(0);
}

int main(){
  cin >> n;
  a = vl(n);
  b = vl(n);
  for(ll i = 0;i < n;i++) cin >> a[i];
  for(ll i = 0;i < n;i++) cin >> b[i];
  for(ll i = 0;;i = (i+1)%n){
    ll prv = (i-1+n)%n;
    ll nxt = (i+1)%n;
    if(b[i] > b[prv] && b[i] > b[nxt] && b[i] > a[i]){
      ll ope = (b[i]-a[i])/(b[prv]+b[nxt]);
      if(ope > 0) cnt = 0;
      ans += ope;
      b[i] = (b[i]-a[i])%(b[prv]+b[nxt])+a[i];
    }
    if(cnt >= n+1) break;
    cnt++;
  }
  // for(ll i = 0;i < n;i++){
  //   cerr << b[i] << " ";
  // }
  // cerr << endl;
  for(ll i = 0;i < n;i++){
    if(a[i] != b[i]) error();
  }
  cout << ans << endl;
}
