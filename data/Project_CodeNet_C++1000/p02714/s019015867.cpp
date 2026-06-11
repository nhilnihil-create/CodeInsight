#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)

using namespace std;

void solve(int N, string S) {
  vector<int> cnt(3, 0);
  REP(i, N) {
    if (S[i] == 'R')
      cnt[0]++;
    if (S[i] == 'G')
      cnt[1]++;
    if (S[i] == 'B')
      cnt[2]++;
  }
  long long ans(1);
  REP(i, 3)
    ans *= cnt[i];
    
  REP(j, N) {
    REP(i, j) {
      const int k = j + (j - i);
      if (k >= N || S[i] == S[j] || S[i] == S[k] || S[j] == S[k])
	continue;
      ans--;
    }
  }
  cout << ans << endl;
}

int main(){
  int N;
  cin >> N;

  string S;
  cin >> S;

  solve(N, S);
  return 0;
}
