#include<bits/stdc++.h>
using namespace std;

int N, A[1000+1][1000+1], idx[1000+1][1000+1];

int memo[1000+1][1000+1], cycle[1000+1][1000+1];
int tsort(auto a, auto b) {
  if(a > b) swap(a, b);
  if(memo[a][b]) return memo[a][b];
  if(cycle[a][b]++) {cout << -1 << endl; exit(0);}
  auto i = idx[a][b] - 1;
  auto j = idx[b][a] - 1;
  auto res = 0;
  if(0 <= i) res = max(res, tsort(a, A[a][i]));
  if(0 <= j) res = max(res, tsort(b, A[b][j]));
  return memo[a][b] = 1 + res;
}

int main() {
  cin >> N;
  for(auto i=0; i<N; ++i) for(auto j=0; j<N-1; ++j) cin >> A[i][j], idx[i][--A[i][j]] = j;
  auto ans = 0;
  for(auto i=0; i<N; ++i) for(auto j=i+1; j<N; ++j) ans = max(ans, tsort(i, j));
  cout << ans << endl;
}
