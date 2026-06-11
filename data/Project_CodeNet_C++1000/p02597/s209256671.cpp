#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define chmin(x,y) x = min(x,y)
int main() {
  int N;
  cin >> N;
  string C;
  cin >> C;
  vector<int> A(N+1,0);
  rep(i,N) {
    A.at(i+1) += A.at(i);
    if (C.at(i) == 'R') {
      A.at(i+1)++;
    }
  }
  //rep(i,N+1) { cout << A[i] << endl;}
  // i番目を含まずひだりをすべてRに、→をWにする。全部Rも考慮せなあかん
  int ans = N - A.at(N); // 全部Rにするとき。
  rep(i,N) {
    int leftW = i - A.at(i);
    int rightR = A.at(N) - A.at(i);
    //cout << leftW << "," << rightR << endl;
    chmin(ans, max(leftW,rightR));
  }
  cout << ans << endl;
  return 0;
}