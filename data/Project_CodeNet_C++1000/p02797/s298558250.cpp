#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N, K, S;
  cin >> N >> K >> S;
  ll num;
  if (S == 1000000000) num = 999999999;
  else num = 1000000000;
  vector<ll> ans(N, num);
  for (int i = 0; i < K; i++) ans[i] = S;
  for (int i = 0; i < N; i++) cout << ans[i] << " ";
  cout << endl;
}
