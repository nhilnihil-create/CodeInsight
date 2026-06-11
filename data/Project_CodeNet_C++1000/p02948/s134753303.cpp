#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1000000007;

ll r(ll x, ll y) {
  if (y == 0) return 1;
  else if (y % 2 == 0) return r(x, y/2) * r(x, y/2) % mod;
  else return x * r(x, (y-1)/2) % mod * r(x, (y-1)/2) % mod;
}


int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> A(1000005, vector<int>(0));
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    A[a].push_back(b);
  }
  for (int i = 0; i < m + 1; i++) {
    if (A[i].size() != 0) {
      sort(A[i].begin(), A[i].end());
    }
  }
  
  ll mo = 0;
  priority_queue<int> q;
  for (int i = 1; i < m + 1; i++) {
    for (int x : A[i]) {
      q.push(x);
    }
    if (!q.empty()) {
      mo += q.top();
      q.pop();
    }
  }
  printf("%lld\n", mo);
}