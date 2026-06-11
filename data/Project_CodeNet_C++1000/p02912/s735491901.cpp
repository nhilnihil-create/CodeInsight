#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> iip;
typedef long long ll;
typedef priority_queue<int> ipque;
typedef priority_queue<long long> llpque;
const int inf = 1000000007;

int main() {
  int n, m;
  cin >> n >> m;
  llpque pque;
  rep(i, n) {
    ll a;
    cin >> a;
    pque.push(a);
  }
  rep(i, m) {
    ll tmp = pque.top() / 2;
    pque.pop();
    pque.push(tmp);
  }
  ll ans = 0;
  while(!pque.empty()){
    ans += pque.top();
    pque.pop();
  }
  cout << ans << endl;
  return 0;
}