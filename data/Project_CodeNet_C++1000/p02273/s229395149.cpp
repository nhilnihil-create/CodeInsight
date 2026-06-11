#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ld> vd;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<vector<ll>> vvll;
typedef vector<pair<ll, ll>> vpll;
typedef priority_queue<ll, vector<ll>, greater<ll>> spqll;  // 小さい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll>> bpqll;     // 大きい順に取り出し

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define IREP(i, v) for (auto i = (v).begin(); i != (v).end(); i++)
#define FI first
#define SE second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define TS to_string
#define NP next_permutation
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) (ll) x.size()
#define SP(x) setprecision((ll)x)


ll INF = 1e9;
ll MOD = 1000000007;
ll LINF = 1e18;
ld EPS = 1e-9;
ld PI = M_PI;
vll dx = {1, 0, -1, 0, 1, -1, -1, 1};
vll dy = {0, 1, 0, -1, 1, 1, -1, -1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}     //最小公倍数

void yes(){ cout << "Yes" << endl;}
void no(){ cout << "No" << endl;}

//-----------------------------------------
struct point{
  ld x, y;
};

void pp(point p){
  cout << p.x << " " << p.y <<endl;
}

void koc(int d, point lef, point rig){
  if(d == 0) return;
  double th = PI / 3;
  point s, t, u;
  s.x = (lef.x * 2 + rig.x) / 3;
  s.y = (lef.y * 2 + rig.y) / 3;
  t.x = (lef.x + rig.x * 2) / 3;
  t.y = (lef.y + rig.y * 2) / 3;
  u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
  u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

  koc(d-1,lef,s);
  pp(s);
  koc(d-1,s,u);
  pp(u);
  koc(d-1,u,t);
  pp(t);
  koc(d-1,t,rig);
}
//-----------------------------------------

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n;
  cin >> n;
  point a, b;
  a.x = 0;
  a.y = 0;
  b.x = 100;
  b.y = 0;
  pp(a);
  koc(n,a,b);
  pp(b);




  return 0;
}

