#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ld> vd;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<pair<ll, ll>> vpll;
typedef priority_queue<ll, vector<ll>, greater<ll>> spqll;  // 小さい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll>> bpqll;     // 大きい順に取り出し

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define IREP(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)
#define FI first
#define SE second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define TS to_string
#define NP next_permutation
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) (ll) x.size()
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

void yes(){ cout << "Yes" << endl;}
void no(){ cout << "No" << endl;}

//-----------------------------------------
vll seen;
vvll graph;
vll indeg;
vll ret;


void init(ll n){
  graph.resize(n);
  indeg.resize(n,0);
  seen.resize(n,0);
  ret.resize(0);
}

void bfs(ll s){
  queue<ll> que;
  que.push(s);
  seen[s] = 1;

  while(!que.empty()){
    ll u = que.front(); que.pop();
    ret.push_back(u);
    for(ll i=0;i<graph[u].size();i++){
      ll v = graph[u][i];
      indeg[v]--;
      if(indeg[v] == 0 && seen[v] == 0){
        seen[v] = 1;
        que.push(v);
      }
    }
  }
}

void T_sort(ll n){
  for(ll i=0;i<n;i++){
    for(ll j=0;j<graph[i].size();j++){
      ll v = graph[i][j];
      indeg[v]++;
    }
  }
  for(ll i=0;i<n;i++){
    if(indeg[i] == 0 && seen[i] == 0){
      bfs(i);
    }
  }
}
//-----------------------------------------

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  ll n;
  cin >> n;
  init(n);
  ll m;
  cin >> m;
  REP(i,m){
    ll s, t;
    cin >> s >> t;
    graph[s].push_back(t);
  }

  T_sort(n);

  REP(i,SZ(ret)) cout << ret[i] <<endl;

  return 0;
}


