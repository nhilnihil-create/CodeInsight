#include <bits/stdc++.h>

#include <iostream>
using namespace std;
#define LL long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, n) for (int i = 0; i <= (n); ++i)
#define rrep(i, n) for (int i = (n)-1; i >= 0; --i)
#define rrep2(i, n) for (int i = (n)-1; i > 0; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define newl '\n'

const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};
int v[2005] = {0};
void solve() {
  int n;
  cin >> n;
  v[3] = v[4] = v[5] = 1;
  int mod = 1e9 + 7;
  for (int i = 6; i <= n; ++i) {
    v[i] = 1;
    for (int j = 3; j <= i - 3; ++j) {
      v[i] = (v[j] + v[i]) % mod;
    }
  }
  cout << v[n];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
