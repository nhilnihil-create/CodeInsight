#include<bits/stdc++.h>
using namespace std;
int main() {
  int H, N;
  cin >> H >> N;
  vector<int> A(N), B(N);
  for(auto i=0; i<N; ++i) cin >> A[i] >> B[i];
  vector<int> memo(H+1);
  function<int(int)> dfs = [&](auto h) {
    if(h <= 0) return 0;
    if(memo[h]) return memo[h];
    int res = 1e9;
    for(auto i=0; i<N; ++i) res = min(res, B[i]+dfs(h-A[i]));
    return memo[h] = res;
  };
  cout << dfs(H) << endl;
}
