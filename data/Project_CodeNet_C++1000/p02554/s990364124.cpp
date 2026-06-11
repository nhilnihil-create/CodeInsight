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
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)
#define all(i,n) (i),(i+n)

int dx4[4]={1,0,-1,0};
int dy4[4]={0,-1,0,1};
int dx8[8]={1,0,-1,1,-1,1,0,-1};
int dy8[8]={1,1,1,0,0,-1,-1,-1};
int dx9[9]={0,1,0,-1,1,-1,1,0,-1};
int dy9[9]={0,1,1,1,0,0,-1,-1,-1};

typedef pair<int, int> P;
typedef pair<string, int> SP;
typedef long long ll;
typedef pair<ll, ll> PLL;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAX_V = 1e6+1;
const ll mod = 1000000007;
// << fixed << setprecision
// --------------------------------------
ll n;
ll mpow(ll x, ll y) {
  ll sum = 1;
  REP(i, y) {
    sum = (sum * x) % mod;
  }
  return sum;
}

ll solve() {
  if(n == 1) return 0;

  ll ans = (mpow(10, n) - ((mpow(9, n) * 2) % mod) + mpow(8, n)) % mod;
  if(ans < 0) ans += mod;
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  ll ans = solve();
  cout << ans << endl;
}
