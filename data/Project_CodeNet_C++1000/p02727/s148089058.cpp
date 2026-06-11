#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;
  vector<int> P(A);
  for (int i = 0; i < A; i++) cin >> P.at(i);
  vector<int> Q(B);
  for (int i = 0; i < B; i++) cin >> Q.at(i);
  vector<int> R(C);
  for (int i = 0; i < C; i++) cin >> R.at(i);
  sort(P.rbegin(), P.rend());
  sort(Q.rbegin(), Q.rend());
  for (int i = 0; i < X; i++) {
    R.push_back(P.at(i));
  }
  for (int i = 0; i < Y; i++) {
    R.push_back(Q.at(i));
  }
  sort(R.rbegin(), R.rend());
  long ans = 0;
  for (int i = 0; i < X + Y; i++) {
    ans += R.at(i);
  }
  cout << ans << "\n";
}