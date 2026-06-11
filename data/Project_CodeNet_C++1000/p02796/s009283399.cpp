#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int main(void){
  int N; cin >> N;
  vector<pair<int, int>> sect(N);
  for (int i = 0; i < N; ++i){
    int X, L; cin >> X >> L;
    sect[i] = {X - L, X + L};
  }

  sort(
    sect.begin(), sect.end(),
    [](auto p, auto q){
      return p.second < q.second;
    }
  );

  int nx = -2000000000;
  int res = 0;
  for (auto s : sect){
    if (s.first >= nx){ // 選択可能
      nx = s.second;
      ++res;
    }
  }

  cout << res << endl;

  return 0;
}