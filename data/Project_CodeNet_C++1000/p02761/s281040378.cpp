#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, b, n) for (int i = b; i < n; ++i)

using namespace std;

void solve(int N, int M, vector<int> s, vector<int> c) {
  auto thisIsIt =[&](const int X) {
    string Xstr = to_string(X);
    REP(i, M)
    if (Xstr[s[i] - 1] - '0' != c[i])
	return false;
    return true;
  };

  FOR(X, N == 1 ? 0 : pow(10, (N - 1)), pow(10, N))
    if (thisIsIt(X)) {
      cout << X << endl;
      return;
    }
  cout << -1 << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  vector<int> s(M);
  vector<int> c(M);
  REP(i, M)
    cin >> s[i] >> c[i];

  solve(N, M, move(s), move(c));

  return 0;
}
