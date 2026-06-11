#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(a.rbegin(), a.rend());
  queue<int> q;
  q.push(a[0]);
  ll ans = 0;
  for (int i = 1; i < n; i++) {
    ans += q.front();
    q.pop();
    q.push(a[i]);
    q.push(a[i]);
  }
  cout << ans << endl;
  return 0;
}