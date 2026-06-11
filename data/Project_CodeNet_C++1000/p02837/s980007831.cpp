#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<pair<int,int>>> evi(N);
  for (int i = 0; i < N; i++) {
    int A;
    cin >> A;
    for (int j = 0; j < A; j++) {
      int x, y;
      cin >> x >> y;
      evi[i].push_back({x-1,y});
    }
  }
  int ans = 0;
  vector<int> fact(N,0);
  for (int tmp = 1; tmp < (1 << N); tmp++) {
    int honest = 0;
    bool b = false;
    bitset<15> s(tmp);
    for (int i = 0; i < N; i++) {
      if (s.test(i)) fact[i] = 1;
    }
    for (int i = 0; i < N; i++) {
      if (s.test(i)) {
        honest += 1;
        for (auto p : evi[i]) {
          if (fact[p.first] != -1 && fact[p.first] != p.second) {
            b = true;
            break;
          }
        }
        if (b) break;
      }
    }
    fact.assign(N,0);
    if (b) continue;
    ans = max(honest,ans);
  }
  cout << ans << endl;
}