#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  for (int i=0; i<N; i++) cin >> A[i];
  // 累積和
  vector<ll> sum(N);
  sum[0] = A[0];
  for (int i=1; i<N; i++) sum[i] = sum[i-1]+A[i];
  vector<ll> ans;
  for (int i=0; i<N-1; i++) {
    if (sum[i]<N-i-1) continue;
    else ans.push_back(abs(2*sum[i]-sum[N-1]));
  }
  sort(ans.begin(), ans.end());
  cout << ans[0] << endl;
}