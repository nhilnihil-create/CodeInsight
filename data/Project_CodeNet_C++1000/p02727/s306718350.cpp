#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T>void show(vector<T>v){for (int i = 0; i < v.size(); i++){cerr<<v[i]<<" ";}cerr<<endl;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }



int main(int argc, char const *argv[]) {
  ll x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<ll> p(a),q(b),r(c),al;
  rep(i,a){
    cin >> p[i];
  }
  rep(i,b){
    cin >> q[i];
  }
  rep(i,c){
    cin >> r[i];
    al.pb(r[i]);
  }
  sort(all(p));
  sort(all(q));
  reverse(all(p));
  reverse(all(q));
  rep(i, x) al.pb(p[i]);
  rep(i, y) al.pb(q[i]);
  sort(all(al));
  reverse(all(al));
  ll ans = 0;
  rep(i, x + y) ans += al[i];
  cout << ans << endl;
  return 0;
}