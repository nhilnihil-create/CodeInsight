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
  int n, k;
  cin >> n >> k;
  int maxv = (n - 1) * (n - 2) / 2;
  if (k > maxv) {
    puts("-1");
    return 0;
  }
  int m = (n - 1) * (n - 2) / 2 - k + n - 1;
  int cur = 0;
  cout << m << endl;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if(cur >= m) break;
      cout << i << " " << j << endl;
      cur++;
    }
  }
}
