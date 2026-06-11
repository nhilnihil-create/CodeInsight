#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int H, W, N;
  cin >> H >> W >> N;

  cout << N / max(H, W) + min(1, N % max(H, W)) << endl;
  return 0;
}