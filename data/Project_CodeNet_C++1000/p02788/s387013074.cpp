#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

const int IN = 100000000;

// Binary Indexed Tree (Fenwick Tree)
template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1) {}
  // 0-indexed
  void add(int i, T x=1) {
    for (i++; i <= n; i += i&-i) {
      d[i] += x;
    }
  }
  // 0-indexed
  T sum(int i) {
    T x = 0;
    for (i++; i; i -= i&-i) {
      x += d[i];
    }
    return x;
  }
  // 半開区間
  T sum(int l, int r) {
    return sum(r-1) - sum(l-1);
  }
};
int main(){
    ll N, D, A; cin >> N >> D >> A;

    vector<pair<ll,ll>> XH(N);
    rep(i,N) cin >> XH[i].first >> XH[i].second;

    sort(XH.begin(), XH.end());

    ll ans = 0;
    BIT<ll> bit(N+1);
    rep(i,N){
        ll x = XH[i].first;
        ll h = XH[i].second;
        h -= bit.sum(i);
        if (h <= 0) continue;
        ll num = (h+(A-1))/A;
        ans += num;
        ll damage = num*A;
        bit.add(i,damage);
        //ll right_end = min(x+D*2, INF);
        ll right_end = x+D*2;        
        pair<ll, ll> right = make_pair(right_end+1, -1);
        int j = lower_bound(XH.begin(), XH.end(), right) - XH.begin();
        bit.add(j, -damage);
    }

    cout << ans << endl;


}