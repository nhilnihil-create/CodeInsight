#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> res(N, 0);
  for (int i = 0; i < N-1; ++i) {
    int a; cin >> a; --a;
    res[a]++;
  }
  for (int i = 0; i < N; ++i) cout << res[i] << endl;
}