#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, K;
  cin >> N >> K;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    if (K <= tmp) ans++;
  }
  cout << ans << endl;
}
