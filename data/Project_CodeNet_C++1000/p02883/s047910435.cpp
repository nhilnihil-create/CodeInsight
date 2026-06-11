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
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;
const int INF = 1001001001;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<int> a(n), f(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> f[i];
  sort(a.begin(), a.end());
  sort(f.rbegin(), f.rend());
  vector<ll> time(n);
  sort(time.begin(), time.end());
  ll l = -1, r = 1e13;
  while(l + 1 < r) {
    ll c = (l + r) / 2;
    bool ok = [&]{
      ll t = 0;
      rep(i, n) {
        t += max(0LL, a[i] - c / f[i]);
      }
      return t <= k;
    }();
    if(ok) r = c;
    else l = c;
  }
  cout << r << endl;
}
