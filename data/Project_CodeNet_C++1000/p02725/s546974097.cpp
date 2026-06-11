#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

template<class T>bool chmax(T &a, const T &b) { if (b>a) { a=b; return 1; } return 0; }


int main() {
  //入力
  int K, N;
  cin >> K >> N;
  vector<int> A(N);
  REP(i, N) cin >> A.at(i);
  
  int t = N, tmax = K + A.at(0) - A.at(N-1);

  REP(i, N-1){
    int d = A.at(i+1) - A.at(i);
    if(chmax(tmax, d)) t = i;
  }

  int ans = 0;
  
  REP(i, N-1){
    if(t != i) ans += A.at(i+1) - A.at(i);
  }
  
  if(t != N) ans += K + A.at(0) - A.at(N-1);
  
  cout << ans << endl;

  return 0;
}
