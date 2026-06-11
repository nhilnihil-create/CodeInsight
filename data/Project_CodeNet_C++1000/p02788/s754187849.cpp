#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
#include<bitset>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,N) for(int (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const double PI = 3.1415926535897932384626433832795;
const int mod = 1000000007;

int main() {
  ll n, d, a;
  cin >> n >> d >> a;
  vector<P> monster(n);
  rep(i, n) {
    ll x, h;
    cin >> x >> h;
    monster[i] = P(x, h);
  }
  sort(monster.begin(), monster.end());

  queue<P> bomb;
  ll ans = 0;
  ll bombnum = 0;

  rep(i, n) {
    ll x = monster[i].first;
    ll h = monster[i].second;
    while (!bomb.empty()) {
      ll bombx = bomb.front().first;
      if (bombx < x) {
        bombnum -= bomb.front().second;
        bomb.pop();
      } else {
        break;
      }
    }

    ll remain = h - (bombnum * a);
    // cout << remain << endl;
    if (remain > 0) {
      ll num = (remain + a - 1) / a;
      ll expire = x + 2 * d;
      bomb.push(P(expire, num));

      ans += num;
      bombnum += num;
    }
  }

  cout << ans << endl;
}