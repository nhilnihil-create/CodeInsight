#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

#define INF 1e9

int gcd(int a, int b){
  if(b==0){
    return a;
  }
  return gcd(b, a % b);
}

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  REP(i, N){
    cin >> A[i];
  }
  int sum = 0;
  REP(i, N){
    sum += A[i];
  }
  set<int> yakusu;
  for(int i = 1; i * i <= sum; i++){
    if(sum % i == 0){
      yakusu.insert(i);
      yakusu.insert(sum / i);
    }
  }
  int ans = 1;
  vector<int> d(N), minus(N+1, 0), plus(N+1, 0);
  for(auto y : yakusu){
    REP(i, N){
      d[i] = A[i] % y;
    }
    sort(d.begin(), d.end());
    REP(i, N){
      minus[i+1] = minus[i]+d[i];
    }
    for(int i = N; i > 0; i--){
      plus[i-1] = plus[i] + (y -d[i-1]);
    }
    FOR(i, 0, N+1){
      if(minus[i] == plus[i] && plus[i] <= K){
        ans = max(ans, y);
      }
    }
  }
  cout << ans <<endl;
  
  return 0;
}
