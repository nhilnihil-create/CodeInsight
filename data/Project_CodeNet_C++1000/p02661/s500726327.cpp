#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

constexpr int INF = 1e9;
// constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;


int main(){
  int N;
  cin >> N;
  vector<ll> A(N), B(N);
  REP(i, N){
    cin >> A[i] >> B[i];
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  int ans;
  if(N % 2){
    ans = B[N/2] - A[N/2] + 1;
  }
  else{
    ans = (2*B[N/2]+2*B[N/2-1])/2 - (2*A[N/2] + 2*A[N/2-1])/2 + 1;
  }
  cout << ans << endl;
  return 0;
}