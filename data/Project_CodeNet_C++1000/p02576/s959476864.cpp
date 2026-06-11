#include <bits/stdc++.h>

using namespace std;

void solve(int N, int X, int T) {
  cout << T * ((N - 1) / X + 1) << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, X, T;
  cin >> N >> X >> T;

  solve(N, X, T);

  return 0;
}
