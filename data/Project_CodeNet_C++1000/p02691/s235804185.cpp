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
#define rep(i,N) for(int (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const double PI = 3.1415926535897932384626433832795;
const int mod = 1000000007;
const int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> jj(n), ii(n);
  rep(i, n) jj[i] = (i + 1) - a[i];
  rep(i, n) ii[i] = a[i] + (i + 1);
  map<int, int> mp;
  ll ans = 0;
  rep(i, n) {
    ans += mp[jj[i]];
    mp[ii[i]]++;
  }
  cout << ans << endl;

}