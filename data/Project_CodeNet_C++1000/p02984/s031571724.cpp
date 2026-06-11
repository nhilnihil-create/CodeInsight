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
  int N; cin >> N;
  vector<ll> a(N); rep(i, N) cin >> a[i];
  ll sum = 0; rep(i, N) sum += a[i];
  ll x1 = sum;
  for (int i = 1; i < N; i += 2){
    x1 -= 2 * a[i];
  }
  cout << x1 << " ";
  for (int i = 0; i < N - 1; ++i){
    x1 = 2 * a[i] - x1;
    cout << x1 << " ";
  }
  cout << endl;
}
