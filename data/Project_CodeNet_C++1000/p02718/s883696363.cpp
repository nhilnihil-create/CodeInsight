#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N, M;
  cin >> N >> M;
  vector <int> A(N);
  rep(i,N) cin >> A.at(i);

  int sum = accumulate(all(A), 0);
  double kagen = sum * 0.25 / M;

  int ans = 0;
  rep(i,N){
    if (A.at(i) >= kagen) ans ++;
  }
  if (ans >= M) cout << "Yes" << endl;
  else cout << "No" << endl;
}
