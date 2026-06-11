#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) int(x.size())

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const double PI=3.14159265358979323846;

int mod = 1e9+7;
const long long INF = 1LL<<60;

int main(){
  int N;
  cin >> N;
  ll D, A;
  cin >> D >> A;
  vector<P> p(N);
  rep(i, N){
    cin >> p[i].first >> p[i].second;
  }
  sort(p.begin(), p.end());
  D = 2*D;
  ll tot = 0;
  queue<pair<ll, ll>> q;
  ll ans = 0;
  rep(i, N){
    ll x = p[i].first;
    ll h = p[i].second;
    while(q.size() && q.front().first < x){
      tot -= q.front().second;
      q.pop();
    }
    h -= tot;
    if(h>0){
      ll num = (h+(A-1)) / A;
      ans += num;
      ll damage = num * A;
      tot += damage;
      q.emplace(x+D, damage);
    }
  }
  cout << ans << endl;
  return 0;
}
