#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll N,K,S;
  cin >> N >> K >> S;
  ll cnt = 0;
  for (int i = 0; i < K; i++) {
    cout << S << " ";
    cnt++;
  }
  for (int i = cnt; i < N; i++) {
    if (S != 1000000000) {
      cout << S+1 << " ";
    } else {
      cout << 1 << " ";
    }
  }
  return 0;
}