#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, c{}; cin >> N; int P[N], Q[N]; for (int &p: P) cin >> p; for (int i{}; i < N; ++i) Q[i] = i + 1;
  for (int i{}; i < N; ++i) c += P[i] != Q[i];
  puts(c < 3 ? "YES" : "NO");}