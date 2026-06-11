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
int n, m;
int prime2(int x) {
  int c = 0;
  while(x % 2 == 0) {
    x /= 2;
    c++;
  }
 
  return c;
}
 
ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}
 
ll lcm(ll a, ll b) {
  if(a < b) swap(a, b);
  return a * b / gcd(a, b);
}
 
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
 
  cin >> n >> m;
 
  vector<int> a(n);
  REP(i, n) cin >> a[i];
 
  int t = prime2(a[0]);
 
  REP(i, n) if(t != prime2(a[i])) {
    cout << 0 << endl;
    return 0;
  }
 
  ll lc = a[0] / 2;
  REP(i, n) {
    lc = lcm(lc, a[i] / 2);
    if(lc > m) {
      cout << 0 << endl;
      return 0;
    }
  }
 
  cout << ((m / lc + 1) / 2) << endl;
}