#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int INF = 1e9+7;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  vector<pair<ll, ll> > xy(N, pair<ll, ll>());
  REP(i, N){
    ll x, y; cin >> x >> y;
    xy[i] = {x, y};
  }
  ll ans = N;
  REP(i, N){
    REP(j, N){
      if(i == j) continue;
      ll p = xy[i].first - xy[j].first;
      ll q = xy[i].second - xy[j].second;
      ll res = 0;
      REP(k, N){
        REP(l, N){
          if(k == l) continue;
          if(p == xy[k].first-xy[l].first && q == xy[k].second-xy[l].second){
            res++;
            break;
          }
        }
      }
      ans = min(ans, N-res);
    }
  }  
  cout << ans << endl;
}