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
  int K, X; cin >> K >> X;
  vector<int> ans;
  ans.push_back(X);
  for (int i = 1; i <= K - 1; i++) {
    if (X - i >= -1000000) ans.push_back(X - i);
    if (X + i <= 1000000) ans.push_back(X + i);
  }
  sort(ans.begin(), ans.end());
  rep(i, ans.size()) cout << ans[i] << " ";
  cout << endl;
}
