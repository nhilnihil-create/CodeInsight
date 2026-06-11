#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <bitset>
#include <set>
#include <deque>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)
#define all(i,n) (i),(i+n)

int dx4[4]={1,0,-1,0};
int dy4[4]={0,-1,0,1};
int dx8[8]={1,0,-1,1,-1,1,0,-1};
int dy8[8]={1,1,1,0,0,-1,-1,-1};

typedef pair<int, int> P;
typedef pair<string, int> SP;
typedef long long ll;
typedef pair<ll, ll> PLL;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAX_V = 1e6+1;
const ll mod = 1000000007;

// --------------------------------------
int n;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  vector<ll> a(n + 1);
  vector<ll> memo(n + 1);

  REP(i, n + 1) cin >> a[i];
  memo[n] = a[n];
  RREP(i, n) {
    memo[i] = memo[i + 1] + a[i];
  }

  ll node = 1;
  REP(i, n + 1) {
    if(node <= 0) {
      cout << -1 << endl;
      return 0;
    }

    if(node < memo[i]) memo[i] = node;
    if(memo[i] < node) node = memo[i];

    node = 2 * (node - a[i]);
    if(i == n && node != 0) {
      cout << -1 << endl;
      return 0;
    }
  }

  ll ans = 0;
  REP(i, n + 1) ans += memo[i];

  cout << ans << endl;
}
