#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;

// i: index, n: size, a: start, b: end
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

// x: container(array, vector etc..)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

#define INF 1000000000000 //10^12
#define MOD 10000007 //10^9+7
#define MAXR 100000 //10^5

#define PB push_back
#define MP make_pair
#define F first
#define S second

signed main() {
  int a, b, v, w, t;
  cin >> a >> v >> b >> w >> t;

  // Aのほうが速度が遅い場合
  if (v <= w) {
    cout << "NO" << endl;
    return 0;
  }

  // Aが追いつける範囲内にいない場合
  int dist = abs(a - b);
  int max_dist = abs((v * t) - (w * t));
  if (dist > max_dist) {
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;

  return 0;
}
