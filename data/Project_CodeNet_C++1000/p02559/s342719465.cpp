#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
#define PI acos(-1)
#define oo LLONG_MAX
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
/*

*/
#define M 500010
ll dat[M];
void init(){
  rep(i,M) dat[i] = 0;
}
void add(ll i, ll x){
  for(; i<M; i += i&-i) dat[i] += x;
}
ll sum(ll i){
  ll res = 0;
  for(; i>0; i -= i&-i) res += dat[i];
  return res;
}
ll rangesum(ll L, ll R){
  return sum(R) - sum(L-1);
}

ll A[M] = {};
vector<ll> QL[M], QID[M];
ll ans[M];

ll N, Q;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  cin >> N >> Q;
  init();
  for(ll i=1; i<=N; i++){
    ll a;
    cin >> a;
    add(i, a);
  }
  rep(i, Q){
    ll t, L, R;
    cin >> t >> L >> R;
    if (t == 0)
      add(L+1, R);
    else
      cout << rangesum(L+1, R) << endl;
  }
}