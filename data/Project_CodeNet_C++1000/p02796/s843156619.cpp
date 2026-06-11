#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll M = 1e9+7;
const ll INF = 1e18;

ll n, ans;
ll a[110000];
priority_queue<P, vector<P>, greater<P> > pq;

int main() {
  cin >> n;

  for (ll i = 0; i < n; i++) {
    ll x, l;
    cin >> x >> l;
    pq.push(P(x+l, x-l));
  }
  
  ans = n;
  ll now = -INF;
  while (!pq.empty()) {
    P p = pq.top();
    pq.pop();
    ll l = p.second;
    ll r = p.first;
    if (l < now) {
      ans--;
      continue;
    }
    now = r;
  }

  cout << ans << endl;
  return 0;
}