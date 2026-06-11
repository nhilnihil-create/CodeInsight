#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> H(N);
  vector<int> B(N, 1);
  for (int i = 0; i < N; i++) cin >> H.at(i);
  int a, b;
  while (cin >> a >> b) {
    a--, b--;
    if (H.at(a) < H.at(b)) B.at(a) = 0;
    else if (H.at(a) > H.at(b)) B.at(b) = 0;
    else B.at(a) = B.at(b) = 0;
  }
  int cnt = 0;
  for (auto b : B) cnt += b;
  cout << cnt << "\n";
}