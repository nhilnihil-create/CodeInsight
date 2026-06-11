#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> p(N);
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    cin >> p[i];
    if (p[i] != i+1) cnt++;
  }
  if (cnt > 2) cout << "NO" << endl;
  else cout << "YES" << endl;
}
