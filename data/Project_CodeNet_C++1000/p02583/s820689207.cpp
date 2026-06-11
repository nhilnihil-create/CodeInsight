#include <bits/stdc++.h>
#define REP(i, n) for (long long i = 0; i < (long long)n; i++)
//#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Vl = vector<ll>;
using vi = vector<int>;
using Graph = vector<vi>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  // std::cout << std::fixed << std::setprecision(15); //"for float-base
  // problem"
  int N;
  cin >> N;
  vi L(N);
  REP(i, N) { cin >> L.at(i); }
  sort(L.begin(), L.end());
  int ans = 0;
  REP(i, N - 2) {
    int a = L.at(i);
    for (int j = i + 1; j < N - 1; j++) {
      int b = L.at(j);
      if (a == b) continue;
      for (int k = j + 1; k < N; k++) {
        int c = L.at(k);
        if (b == c || a + b <= c) continue;
        ans++;
      }
    }
  }

  cout << ans << endl;
}