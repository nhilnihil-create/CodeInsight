#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<ld> vld;
typedef vector<string> vstr;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef priority_queue<ll, vector<ll>, greater<ll>> spqll;  // 小さい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll>> bpqll;     // 大きい順に取り出し

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define IREP(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)
#define ALL(v) (v).begin(), (v).end()
#define endl "\n"

ll INF = 1e9;
ll MOD = 1000000007;
ll LINF = 1e18;
ld EPS = 1e-9;
ld PI = M_PI;
vll dx = {1, 0, -1, 0, 1, -1, -1, 1};
vll dy = {0, 1, 0, -1, 1, 1, -1, -1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}     //最小公倍数

void yes(){ cout << "YES" << endl;}
void no(){ cout << "NO" << endl;}

//-----------------------------------------
//-----------------------------------------
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  ll n, k;
  cin >> n >> k;

  vll a(n);
  vll seen(n,0);
  vll dis(n,INF);

  REP(i,n) {cin >> a[i]; a[i]--;}

  ll x, y;
  seen[0] = 1;
  dis[0] = 0;
  ll j = 0;

  while(1){
    ll tmp = a[j];
    if(seen[tmp] == 0){
      dis[tmp] = dis[j] + 1;
      seen[tmp] = 1;
    }
    else{
      x = dis[tmp];
      y = dis[j] - dis[tmp] + 1;
      break;
    }
    j = tmp;
  }

  //cout << x << " " << y  << endl;

  if(k < x){
    REP(i,n) if(dis[i] == k) cout << i+1 <<endl;
  }
  else{
    REP(i,n) if(dis[i] == (k - x) % y + x) cout << i + 1 <<endl;
  }



  return 0;
}

