#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


int main() {
  //入力
  int K, N;
  cin >> K >> N;
  vector<int> A(N);
  REP(i, N) cin >> A.at(i);

  //一個目のやつを最後にもう一個くっつけます
  A.push_back(A.at(0)+K);

  int ans = 1000000000;

  REP(i, N){
    //こうすると、間だけを考えればいいことになります
    int d = A.at(i+1) - A.at(i);
    chmin(ans, K - d);
  }

  cout << ans << endl;

  return 0;
}
