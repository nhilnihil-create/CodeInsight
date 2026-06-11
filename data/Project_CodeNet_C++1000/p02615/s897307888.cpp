#include <bits/stdc++.h>

#define nl '\n'

using namespace std;

typedef long long ll;

void solve() {
  int N;
  cin >> N;
  int A[N];
  for (int& i : A)
    cin >> i;

  sort(A, A + N, greater<int>());
  vector<int> comf;
  ll comfort = A[0];
  for (int i = 1; i < N; i++) comf.push_back(A[i]), comf.push_back(A[i]);
  for (int i = 0; i < N-2; i++) comfort += comf[i];

  cout << comfort;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // int t;
  // cin >> t;
  // while (t--) {
  solve();
  cout << nl;
  // }

  return 0;
}