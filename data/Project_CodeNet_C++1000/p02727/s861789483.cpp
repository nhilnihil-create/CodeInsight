#include <bits/stdc++.h>

using namespace std;
typedef uint64_t u64;
typedef int64_t i64;
typedef double db;

i64 X, Y, A, B, C;
deque<i64> P, Q, R;

int main() {
  cin >> X >> Y >> A >> B >> C;
  for (int i = 0; i < A; i++) {i64 v; cin >> v; P.push_back(v);}
  for (int i = 0; i < B; i++) {i64 v; cin >> v; Q.push_back(v);}
  for (int i = 0; i < C; i++) {i64 v; cin >> v; R.push_back(v);}
  sort(P.begin(), P.end(), [](i64 l,i64 r) { return l - r > 0ll; });
  sort(Q.begin(), Q.end(), [](i64 l,i64 r) { return l - r > 0ll; });
  P.resize(X);
  Q.resize(Y);
  R.insert(R.end(), P.begin(), P.end());
  R.insert(R.end(), Q.begin(), Q.end());
  sort(R.begin(), R.end(), [](i64 l,i64 r) { return l - r > 0ll; });
  R.resize(X + Y);
  cout << accumulate(R.begin(), R.end(), 0ll) << endl;
  return 0;
}
