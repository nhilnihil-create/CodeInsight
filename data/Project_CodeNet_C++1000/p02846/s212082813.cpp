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
ll t1, t2, a1, a2, b1, b2;

ll solve() {
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;

  ll s1 = t1 * (a1 - b1);
  ll s2 = t2 * (a2 - b2);

  ll p1 = s1, p2 = p1 + s2;
  ll ans = 0;
  if(p2 == 0) {
    ans = LLINF;
  } else if(p1 > 0 && p2 < 0) {
    ans++;
    ans += (s1 / abs(p2)) * 2;
    if(s1 / abs(p2) > 0 && s1 % abs(p2)  == 0) ans--;
  } else if(p1 < 0 && p2 > 0) {
    ans++;
    ans += (abs(s1) / p2) * 2;
    if(abs(s1) / p2 > 0 &&  abs(s1) % p2 == 0) ans--;
  }
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll ans = solve();
  if(ans == LLINF) cout << "infinity" << endl;
  else cout << ans << endl;;
}
