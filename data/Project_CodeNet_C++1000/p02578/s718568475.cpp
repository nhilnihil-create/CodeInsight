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

  ll height = 0;
  for (int i = 0, maxheight = 0; i < N; i++) {
    maxheight = max(maxheight, A[i]);
    height += maxheight - A[i];
  }

  cout << height;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  // int t;
  // cin >> t;
  // while (t--) {
  solve();
  // }

  return 0;
}