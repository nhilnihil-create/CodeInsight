#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include<functional>
#include<numeric>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<set>
#include<bitset>
#include<random>
#pragma region
using namespace std;
#define FOR(i,r,n) for(ll i = (ll)(r); i < (ll)(n); i++)
#define rep(i,n) FOR(i,0LL,n)
#define RFOR(i,r,n) for(ll i=(ll)(n-1);i>=r;i--)
#define rrep(i,n) RFOR(i,0LL,n)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define COUNT(a,y,x) upper_bound(all(a), y) - lower_bound(all(a), x)
#define UNIQUE(a) sort(all(a)); a.erase(unique(all(a)), a.end())
#define pb push_back
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef map<ll, ll> MAP;
const ll inf = 1LL << 61;
const ll mod = 1000000007LL;
//const ll mod = 998244353LL;

ll n = 0, m = 0, ans = 0, tmp = 0, ma = -inf, mi = inf;
string s;
ll dx[9] = { 0,1,0,-1,0,1,1,-1,-1 }, dy[9] = { 0,0,1,0,-1,1,-1,1,-1 };
#define endl '\n'
#pragma endregion
#define MAX 222222



ll edge[555][555];

void fac(ll le, ll ri, ll num) {
  ll mid = (le + ri) / 2;
  if (ri == le) return;
  FOR(i, le, mid + 1) FOR(j, mid + 1, ri + 1) {
    edge[i][j] = num;
    edge[j][i] = num;
  }
  fac(le, mid, num + 1);
  fac(mid + 1, ri, num + 1);
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(0);


  cin >> n;
  fac(1, n, 1);
  FOR(i, 1, n) {
    FOR(j, i + 1, n + 1) cout << edge[i][j] << " ";
    cout << endl;
  }


  return 0;
}
