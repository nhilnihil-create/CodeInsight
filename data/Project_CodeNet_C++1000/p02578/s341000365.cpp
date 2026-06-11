#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);

  long ans = 0, mx = 0;
  auto cmax = [&](auto& a, auto b) { if (a < b) a = b; };
  for (auto a : A) {
    if (a < mx) ans += mx - a;
    cmax(mx, a); 
  }
  cout << ans << "\n";
}