#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
  string S;
  long long K;
  cin >> S >> K;

  string M = S;
  set<char> Set;
  int cnt = 0;
  for (int i = 0; i < M.size() - 1; i++) {
    if (M.at(i) == M.at(i + 1)) {
      cnt++;
      M.at(i + 1) = 'C';
      Set.insert(M.at(i));
    }
  }

  string L = S + S;
  int cnt2 = 0;
  for (int i = 0; i < L.size() - 1; i++) {
    if (L.at(i) == L.at(i + 1)) {
      cnt2++;
      L.at(i + 1) = 'C';
    }
  }

  if (Set.size() == 1 || S.size() == 1) {
    cout << S.size() * K / 2 << endl;
    return 0;
  }

  if (S.at(0) != S.at(S.size() - 1))
    cout << cnt * K << endl;
  else
    cout << cnt + (K - 1) * (cnt2 - cnt) << endl;
}
