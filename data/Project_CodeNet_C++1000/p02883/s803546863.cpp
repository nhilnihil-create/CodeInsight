#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

ll N, K;
vector<ll> A;
vector<ll> F;

bool func(ll x){
  ll k = K;
  REPLL(i, N){
    k -= max(A[i]-x/F[i], 0LL);
    if(k < 0) return false;
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  A.assign(N, 0);
  F.assign(N, 0);
  REP(i, N){
    cin >> A[i];
  }
  REP(i, N){
    cin >> F[i];
  }
  sort(A.begin(), A.end());
  sort(F.begin(), F.end(), greater<ll>());
  ll leftNG = -1;
  ll rightOK = 1e12+5;
  ll mid = (leftNG+rightOK)/2;
  while(rightOK - leftNG > 1){
    if(func(mid)){
      rightOK = mid;
    }else{
      leftNG = mid;
    }
    mid = (leftNG+rightOK)/2;
  }
  cout << rightOK << endl;
}