#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i = 0; i < n; i++)
#define per(i,n) for(ll i = n-1; i >= 0; i--)
#define REP(i,n) for(ll i = 1; i < n; i++)
#define PER(i,n) for(ll i = n; i >= 1; i--)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;
using vs = vector<string>;
using vb = vector<bool>;
using vc = vector<char>;
using vcc = vector<vc>;
using vP = vector<P>;
using vPP = vector<vP>;
using vPl = vector<Pl>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main(){
  ll n, k;
  cin >> n >> k;
  vi a(n), f(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> f[i];
  sort(all(a));
  sort(rall(f));
  ll l = -1, r = 1e12;
  while(l+1 < r) {
    ll mid = (l+r)/2;
    ll cnt = 0;
    rep(i,n) {
      ll d = a[i] - mid / f[i];
      if(d > 0) cnt += d;
    }
    if(cnt <= k) r = mid;
    else l = mid;
  }
  cout << r << endl;
}