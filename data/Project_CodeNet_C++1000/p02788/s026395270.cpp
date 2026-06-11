#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N, D, A; cin >> N >> D >> A;
  vector<pair<ll, ll> > XI(N, pair<ll, ll>());
  vector<ll> X(N, 0);
  vector<ll> H(N, 0);
  vector<ll> AA(N+1, 0);
  REPLL(i, N){
    ll x, h; cin >> x >> h;
    XI[i] = {x, i};
    X[i] = x;
    H[i] = h;
  }
  sort(XI.begin(), XI.end());
  sort(X.begin(), X.end());
  ll ans = 0;
  REP(i, N){
    if(i != 0){
      AA[i] += AA[i-1];
    }
    ll hh = H[XI[i].second];
    ll a = ((hh-AA[i]*A+(A-1))/A < 0 ? 0 : (hh-AA[i]*A+(A-1))/A);
    ans += a;
    AA[i] += a;
    ll dis = X[i]+2*D;
    auto itr = lower_bound(X.begin(), X.end(), dis);
    ll idx = *itr;
    if(idx == dis){
      AA[itr-X.begin()+1] += -a;
    }else{
      AA[itr-X.begin()] += -a; 
    }
  }
  cout << ans << endl;
}