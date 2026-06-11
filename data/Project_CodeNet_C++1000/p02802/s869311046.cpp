#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> B(N);
  vector<int> wa(N);
  for (int i = 0; i < M; i++) {
    int P;
    string S;
    cin >> P >> S;
    P--;
    if (B.at(P)) continue;
    if (S == "AC") B.at(P) = 1;
    else wa.at(P)++;
  }
  cout << accumulate(B.begin(), B.end(), 0L) << "\n";
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (B.at(i)) ans += wa.at(i);
  }
  cout << ans << "\n";
}