#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<deque>
#include<queue>
using namespace std;

using ll = long long;
const int INF = 1001001001;

#define rep(i,n) for (int i = 0; i < (n); ++i)

int main()
{
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> day(m+1);
  priority_queue<ll> today;

  rep(i,n) {
    ll a, b;
    cin >> a >> b;
    if (m-a+1 < 1) continue;
    day[m-a+1].push_back(b);
  }

  ll result = 0;
  for (ll i = m; i >= 1; i--) {
    if (!day[i].empty()) {
      for (auto x : day[i]) {
        today.push(x);
      }
    }
    if (!today.empty()) {
      result += today.top(); today.pop();
    }
  }

  cout << result << endl;
}
