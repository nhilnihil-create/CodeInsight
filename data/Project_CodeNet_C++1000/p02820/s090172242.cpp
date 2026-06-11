#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  int R, S, P;
  cin >> R >> S >> P;

  string T;
  cin >> T;

  auto to_score = [=](char c)
  {
    if (c == 'r') return P;
    if (c == 's') return R;
    return S;
  };

  vector<bool> skipped(N, false);
  int score = 0;
  rep(i,0,N-1)
  {
    if (i < K)
      score += to_score(T[i]);
    else
    {
      if (T[i] == T[i-K] && !skipped[i-K])
        skipped[i] = true;
      else
        score += to_score(T[i]);
    }
  }

  cout << score << endl;
  return 0;
}
