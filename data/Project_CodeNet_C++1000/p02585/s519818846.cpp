#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
#define PI acos(-1)
#define oo LLONG_MAX
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
/*

*/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  ll N, K;
  cin >> N >> K;
  vector<ll> P(N+1, 0), C(N+1, 0);
  rep(i, N) cin >> P[i+1];
  rep(i, N) cin >> C[i+1];
  ll ans = -4e18;
  rep(i, N){
    ll k = K, tmp = 0, now = i+1, next = P[now];
    vector<int> seen(N+1, 0);
    while (seen[next] < 2 && k > 0){
      seen[next]++;
      tmp += C[next];
      now = next;
      next = P[now];
      chmax(ans, tmp);
      k--;
    }
    ll loop = 0, add = 0;
    rep(i, N+1){
      if (seen[i] == 2){
        loop++;
        add += C[i];
      }
    }
    ll cnt = 0;
    if (loop > 0)
      cnt = k/loop;
    cnt--;
    if (cnt > 0){
      tmp += add * cnt;
      k -= loop * cnt;
    }
    chmax(ans, tmp);
    while (k > 0){
      tmp += C[next];
      now = next;
      next = P[now];
      chmax(ans, tmp);
      k--;
    }
  }
  cout << ans << endl;
}
