#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, K; cin >> N >> K;
  int H[N]; for (int &h: H) cin >> h; sort(H, H + N);
  cout << accumulate(H, H + max(0, N - K), 0LL);}