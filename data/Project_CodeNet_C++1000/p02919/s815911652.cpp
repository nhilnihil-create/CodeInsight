#include <bits/stdc++.h>
using namespace std;

// types
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;

// macros
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define FI first
#define SE second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define REP1(i,n) for(int i=1;i<((int)n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define PB push_back
#define EB emplace_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL

// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;

  vll p(n);
  REP(i, n){
    cin >> p[i];
    p[i]--;
  }

  vll index(n);
  REP(i, n)
    index[p[i]] = i;

  set<ll> s;
  ll ans = 0;
  for(ll i = n-1; i >= 0; i--){
    s.insert(index[i]);
    vll l(2, -1), r(2, n);
    {
      auto it = s.find(index[i]);
      REP(j, 2){
        if(it == s.begin())
          break;
        it--;
        l[j] = *it;
      }
    }
    {
      auto it = s.find(index[i]);
      REP(j, 2){
        it++;
        if(it == s.end())
          break;
        r[j] = *it;
      }
    }

    auto it = s.find(index[i]);
    vll ls(2), rs(2);
    ls[0] = *it - l[0];
    ls[1] = l[0] - l[1];
    rs[0] = r[0] - *it;
    rs[1] = r[1] - r[0];



    ans += (i+1)*(rs[0]*ls[1]+rs[1]*ls[0]);
  }

  cout << ans << endl;
}
