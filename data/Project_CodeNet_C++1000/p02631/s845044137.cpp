#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i,N) cin >> a[i];

  int S = 0;
  rep(i,N) S ^= a[i];
  vector<int> b(N);
  rep(i,N) b[i] = S ^ a[i];
  rep(i,N-1) cout << b[i] << " ";
  cout << b[N-1] << endl;;
  return 0;
}