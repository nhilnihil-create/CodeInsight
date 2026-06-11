#include <bits/stdc++.h>

using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, K;
  cin >> N >> K;

  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  ll sumA = 0;
  rep(i, N) sumA += A[i];

  ll ans = 0;
  for(ll T = 1; T * T <= sumA; T++){

    if(sumA % T == 0){
    vector<ll> subvec(N);

    ll sum_pos = 0;
    rep(i, N){
      subvec[i] = A[i] % T;
      sum_pos += (T - subvec[i]);
    }

    sort(subvec.begin(), subvec.end());

    ll sum_neg = 0;

    rep(i, N){

      sum_neg += subvec[i];
      sum_pos -= (T - subvec[i]);

      if(sum_neg == sum_pos){
        if(sum_neg <= K){
          chmax(ans, T);
        }else{
          break;
        }
      }

    }

    vector<ll> subvec2(N);
    ll TT = sumA / T;
    sum_pos = 0;
    rep(i, N){
      subvec2[i] = A[i] % TT;
      sum_pos += (TT - subvec2[i]);
    }

    sort(subvec2.begin(), subvec2.end());

    sum_neg = 0;

    rep(i, N){

      sum_neg += subvec2[i];
      sum_pos -= (TT - subvec2[i]);

      if(sum_neg == sum_pos){
        if(sum_neg <= K){
          chmax(ans, TT);
        }else{
          break;
        }
      }

    }
    }
  }

    ll T = sumA;
    vector<ll> subvec(N);

    ll sum_pos = 0;
    rep(i, N){
      subvec[i] = A[i] % T;
      sum_pos += (T - subvec[i]);
    }

    sort(subvec.begin(), subvec.end());

    ll sum_neg = 0;

    rep(i, N){

      sum_neg += subvec[i];
      sum_pos -= (T - subvec[i]);

      if(sum_neg == sum_pos){
        if(sum_neg <= K){
          chmax(ans, T);
        }else{
          break;
        }
      }
    }

  cout << ans << endl;



  return 0;
}
