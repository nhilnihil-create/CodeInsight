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
  int N, M; cin >> N >> M;
  vector<vector<int>> jobs(M);
  rep(i, N){
    int a, b; cin >> a >> b;
    if (a > M) continue;
    jobs[M - a].push_back(b);
  }
  priority_queue<int, vector<int>> q;
  ll ans = 0;
  for (int i = M - 1; i >= 0; --i){
    for (int b: jobs[i]){
      q.push(b);
    }
    if (!q.empty()){
      ans += q.top();
      q.pop();
    }
  }
  cout << ans << endl;
}
