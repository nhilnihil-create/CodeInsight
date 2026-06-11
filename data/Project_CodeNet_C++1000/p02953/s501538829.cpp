#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  int N;
  cin >> N;
  
  vector<int> H(N);
  rep(i, N) {
    cin >> H[i];
  }

  reverse(H.begin(), H.end());
  int prev = H[0];
  for(int i = 1; i < N; ++i) {
    if (prev < H[i]) {
      if (prev < --H[i]) {
        cout << "No" << endl;
        return 0;
      }
    }
    prev = H[i];
  }

  cout << "Yes" << endl;

  return 0;
}