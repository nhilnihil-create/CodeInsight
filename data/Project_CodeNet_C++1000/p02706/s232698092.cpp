#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N, M;
  cin >> N >> M;
  vector <int> A(M);
  rep(i,M) cin >> A.at(i);

  int sum = accumulate(all(A), 0);
  int ans = max(-1, N - sum);
  cout << ans << endl;
}
