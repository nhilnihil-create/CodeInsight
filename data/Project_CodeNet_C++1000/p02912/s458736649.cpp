#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
 
int main() {
  int n, m;
  cin >> n >> m;
  priority_queue<int> q;
  rep(i,n) {
    int a;
    cin >> a;
    q.push(a);
  }
  rep(i,m) {
    int a = q.top(); q.pop();
    q.push(a/2);
  }
  ll ans = 0;
  rep(i,n) {
    ans += q.top(); q.pop();
  }
  cout << ans << endl;
  return 0;
}