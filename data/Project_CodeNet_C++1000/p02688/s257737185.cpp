#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, K, ans{}; cin >> N >> K;
  vector<bool> bs(N);
  while (K--) {int d; cin >> d; while (d--) {int A; cin >> A; bs[--A] = true;}}
  for (auto b : bs) ans += !b;
  cout << ans << endl;}