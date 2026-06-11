#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
  int N;
  cin >> N;

  int W[N];
  int totalSum=0;
  for (int i = 0; i < N; i++) {
    cin >> W[i];
    totalSum += W[i];
  }

  int ans = INF;
  int S1 = 0;
  for (int i = 0; i < N-1; i++) {
    S1+=W[i];
    int S2=totalSum-S1;
    ans = min(ans,abs(S2-S1));
  }

  cout << ans << endl;
  return 0;
}