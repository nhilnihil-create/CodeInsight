#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;

void solve(long N, vector<long> A) {
  ll ans = 0;
  unordered_map<long, long> i_pl;
  unordered_map<long, long> i_mi;
  rep(i, N) {
    i_pl[i+A[i]]++;
    i_mi[i-A[i]]++;
  }
  for(auto& pair : i_pl) {
    long x = pair.first;
    if (!i_mi[x])
      continue;
    ans += i_pl[x] * i_mi[x];
  }
    
  cout << ans << endl;
}

int main(){
  // int 3E4  long 2E9  ll 9E18
  cin.tie(0);
  ios::sync_with_stdio(false);

  long N;
  cin >> N;

  vector<long> A(N);
  rep(i, N)
    cin >> A[i];

  solve(N, move(A));

  return 0;
}
