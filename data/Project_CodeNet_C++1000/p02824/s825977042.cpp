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
  ll N, M, V, P; cin >> N >> M >> V >> P;
  vector<ll> A(N, 0);
  REPLL(i, N){
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  vector<ll> AA(N, 0);
  REPLL(i, N){
    if(i){
      AA[i] = AA[i-1] + A[i];
    }else{
      AA[i] = A[i];
    }
  }
  ll res = 0;
  REPLL(i, N-P){
    if(A[N-P] > A[i]+M || (N-P-i)*(A[i]+M)-(AA[N-P]-AA[i]) < M*V-M*(P+i > V ? V : P+i)){
      res++;
    }
  }
  cout << N - res << endl;
}