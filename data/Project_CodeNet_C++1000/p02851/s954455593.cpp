#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <cmath>

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

const ll MOD = 1000000007;
const int INF = 1<<30;
//const ll INF = (ll)1e18 + 1;

int main(){
  ll N, K; cin >> N >> K;
  vector<ll> a(N); rep(i, N) cin >> a[i];

  vector<ll> s(N + 1, 0);
  rep(i, N){
    s[i + 1] = s[i] + a[i];
    s[i + 1] %= K;
  }

  map<ll, ll> mp;
  ll ans = 0;
  queue<ll> que;
  rep(r, N + 1){
    ll x = (s[r] - r) % K;
    if (x < 0) x += K;
    ans += mp[x];
    mp[x]++;

    que.push(x);
    if (que.size() >= K){
      mp[que.front()]--;
      que.pop();
    }
  }
  cout << ans << endl;
}
