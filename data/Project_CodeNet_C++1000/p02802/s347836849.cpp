#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, M;
  cin >> N >> M;
  int AC = 0, WA = 0;
  vector<int> eachWA(N+1);
  vector<bool> solved(N+1, 0);  // 1-indexed
  rep(i, M) {
    int P;
    string S;
    cin >> P >> S;
    if (solved[P]) continue;
    if (S == "AC") {
      AC++;
      WA += eachWA[P];
      solved[P] = true;
    } else {
      eachWA[P]++;
    }
  }
  cout << AC << ' ' << WA << '\n';
  return 0;
}