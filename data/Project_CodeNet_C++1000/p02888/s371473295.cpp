#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> L(N);
  rep(i,0,N-1) cin >> L[i];

  sort(L.begin(), L.end());

  long long ans = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      for (int k = j + 1; k < N; ++k) {
        if (L.at(i) + L.at(j) <= L.at(k)) break;
        ans++;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
