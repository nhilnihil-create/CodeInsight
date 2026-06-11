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
  string S; cin >> S;
  ll K; cin >> K;
  ll N = S.length();

  ll ans = 0;
  ll cnt = 0;
  rep(i, N) if (S[0] == S[i]) cnt++;

  if (cnt == N) {
    cout << N * K / 2 << endl;
    return 0;
  }
  if (S[0] != S[N - 1]) {
    rep(i, N){
      ll length = 1;
      while (i + 1 < N && S[i] == S[i + 1]) i++, length++;
      ans += length / 2 * K;
    }
  }
  else {
    vector<ll> que;
    rep(i, N){
      ll length = 1;
      while (i + 1 < N && S[i] == S[i + 1]) i++, length++;
      que.push_back(length);
    }
    for (int i = 1; i < (int)que.size() - 1; ++i) ans += que[i] / 2 * K;
    ans += que[0] / 2;
    ans += que[(int)que.size() - 1] / 2;
    ans += (que[0] + que[(int)que.size() - 1]) / 2 * (K - 1);
  }
  cout << ans << endl;
}
