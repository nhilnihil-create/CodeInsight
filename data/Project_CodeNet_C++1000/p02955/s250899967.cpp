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
int n, k;

vector<int> divisor(int n) {
  vector<int> res;
  for(int i=1; i*i<=n; i++) {
    if(n % i == 0) {
      res.push_back(i);
      if(i != n / i) res.push_back(n / i);
    }
  }
  return res;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  vector<int> a(n);

  int sum = 0;
  REP(i, n) {
    cin >> a[i];
    sum += a[i];
  }

  auto v = divisor(sum);

  int ans = 1;
  REP(i, v.size()) {
    vector<int> r(n);
    REP(j, n) r[j] = a[j] % v[i];
    sort(r.begin(), r.end());

    ll B = 0;
    REP(j, n) B += v[i] - r[j];
    ll A = 0;
    ll need = 1e18;
    REP(j, n) {
      A += r[j];
      B -= v[i]-r[j];
      need = min(need, max(A, B));
    }

    if(need <= k) ans = max(v[i], ans);
  }

  cout << ans << endl;
}
