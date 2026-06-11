#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N;
  cin >> N;
  vector <int> A(N), B(N), C(N - 1);
  rep(i,N) cin >> A.at(i);
  rep(i,N) cin >> B.at(i);
  rep(i,N-1) cin >> C.at(i);

  int ans = 0;
  rep(i,N){
    ans += B.at(A.at(i) - 1);
    if (i > 0 && A.at(i) == A.at(i - 1) + 1){
      ans += C.at(A.at(i - 1) - 1);
    }
  }
  cout << ans << endl;
}
