#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int cnt = 0;
  for (int i = 0; i < N; ++i) {
    int a; cin >> a; --a;
    if (a != i) ++cnt;
  }
  if (cnt <= 2) cout << "YES" << endl;
  else cout << "NO" << endl;
}