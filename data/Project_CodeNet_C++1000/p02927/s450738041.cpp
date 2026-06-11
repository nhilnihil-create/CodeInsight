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
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;
const int INF = 1001001001;

int main() {
  int m, d;
  cin >> m >> d;
  int ans = 0;
  for (int j = 1; j <= m; ++j) {
    for (int i = 1; i <= d; ++i) {
      int d1 = i % 10;
      int d2 = i / 10;
      if(d1 >= 2 && d2 >= 2 && d1 * d2 == j) ++ans;
    }
  }
  cout << ans << endl;

}