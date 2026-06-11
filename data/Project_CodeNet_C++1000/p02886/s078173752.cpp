#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;
using Graph = vector<vector<int>>;

int main() {
  int N;
  cin >> N;
  int d[N];
  int sum = 0;

  rep (i, N) cin >> d[i];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) continue;
      sum += d[i] * d[j];
    }
  }

  int ans = sum / 2;
  cout << ans << endl;

  return 0;
}
