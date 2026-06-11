#pragma gcc optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define FOR(i,r,n) for(ll i=(ll)(r);i<(ll)(n);++i)
#define RFOR(i,r,n) for(ll i=(ll)(n-1);i>=r;--i)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define pb(n) push_back(n)
#define endl '\n'
#define debug(x) cout << #x << " = " << (x) << endl
#define IN(n) cin >> n
#define IN2(a,b) cin >> a >> b
#define IN3(a,b,c) cin >> a >> b >> c
#define VIN(V) for(int ii = 0; ii < (V).size(); ii++) {cin >> (V).at(ii);}
#define OUT(n) cout << n << endl
#define OUT2(n1,n2) cout << n1 << " " << n2 << endl
#define OUT3(n1,n2,n3) cout << n1 << " " << n2 << " " << n3 << endl
#define VOUT(V) REP(ii,(V).size()){cout << (V)[ii] << " ";} cout<<endl;
#define VOUT2(V) REP(jj,(V).size()){VOUT(V[jj])}
typedef long long int ll;
typedef vector<ll> vi;
typedef vector<vi > vvi;
typedef vector<pair<ll, ll> > vp;
typedef vector<string> vs;
typedef vector<char> vc;
typedef list<ll> lst;
typedef pair<ll, ll> P;
const long long INF = numeric_limits<ll>::max();
const long long MOD = 1000000007;
const long double PI = 3.1415926;
template <class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <class T> T &chmax(T &a, const T &b) { return a = max(a, b); }
ll n, m, k, ans, sum, cnt = 0; string s; char c; bool flg;

int main(){
  cin.tie(0);ios::sync_with_stdio(false);
  IN2(n,k);

  ll a,b;
  unordered_map<ll, set<ll>> edges;
  FOR(i,0,n) {
    IN2(a,b);
    edges[a].insert(b);
    edges[b].insert(a);
  }

  queue<P > q;
  q.push(P(1,0));
  vector<bool> visited(n+1);
  FOR(i,0,n+1) visited[i] = false;
  visited[1] = true;
  ans=1;
  while (!q.empty()) {
    P now = q.front(); q.pop();
    // debug(now.first);

    set<ll> now_edges = edges[now.first];
    ll now_gensui = now.second;
    ans = ans * (k-now_gensui) % MOD;

    if (now_gensui < 2) now_gensui++;
    else now_gensui = 2;

    ll bunki_count = 0;
    for(auto x : now_edges) {
      if (visited[x]) continue;
      q.push(P(x,now_gensui + bunki_count));
      bunki_count++;
      visited[x] = true;
    }
  }

  OUT(ans);
}
