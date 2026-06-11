#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <cctype>
using namespace std;

#define rep(i,n) for(int (i)=0; (i)<(int)(n); ++(i))
#define foreach(c,i) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
typedef long long ll;
int n,k,a[100002];
ll sum[100002];
const int INF = 1<<28;

void solve() {
  rep(i,n) cin>>a[i];
  sum[0]=0;
  rep(i,n) sum[i+1]=sum[i]+a[i];
  ll ans = -INF;
  //rep(i,n+1) cout<<sum[i]<<endl;
  for(int i=0; i+k<=n; ++i) {
    ans = max(ans, sum[i+k]-sum[i]);
  }
  cout<<ans<<endl;
}
int main() {
  while(cin>>n>>k,n) solve();
  return 0;
}