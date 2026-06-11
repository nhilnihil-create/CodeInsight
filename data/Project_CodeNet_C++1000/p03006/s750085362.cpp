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
  int n;
  cin >> n;
  vector<P> v(n);
  rep(i, n) cin >> v[i].first >> v[i].second;
  sort(v.begin(), v.end());
  int cost = 1;
  int sub = 0;
  rep(i, n) rep(j, n) {
    if(i == j) continue;
    int p = v[i].first - v[j].first;
    int q = v[i].second - v[j].second;
    int t = 0;
    rep(k, n) rep(l, n) {
      if(k == l) continue;
      if(v[k].first - v[l].first == p && v[k].second - v[l].second == q) ++t;
    }
    sub = max(sub, t);
  }
  cout << n - sub << endl;

}
