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
#include <bitset>

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
  ll N, K, S; cin >> N >> K >> S;
  vector<ll> a(N);
  rep(i, K) a[i] = S;
  if (S < 1000000000){
    for (int i = K; i < N; ++i) a[i] = S + 1;
  }
  else {
    for (int i = K; i < N; ++i) a[i] = 1;
  }
  rep(i, N) cout << a[i] << " ";
  cout << endl;
}
