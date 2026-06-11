#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i,N) cin >> A[i];

  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());

  ll ans = 0;
  priority_queue<int> q;
  q.push(A[0]);
  for (int i = 1; i < N; i++) {
    ans += q.top();
    q.pop();
    q.push(A[i]);
    q.push(A[i]);
  }
  cout << ans << endl;
  return 0;
}