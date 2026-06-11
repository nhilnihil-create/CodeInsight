#include <bits/stdc++.h>
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define int long long
#define vll vector<long long>
#define pii pair<long long ,long long >
#define vvi vector< vector<long long > >
#define vpii vector<pair<int,int>>
#define pll  pair<long long ,long long >
#define pb  push_back
#define ff  first
#define sec second
#define SORT(a) sort(a.begin(),a.end())
#define SORTR(a) sort(a.rbegin(),a.rend())
#define m_p make_pair
#define all(x) (x.begin(),x.end())
#define sz(v) ((int)(v.size()))
#define endl '\n'
typedef vector< long long > vi ;
const int MOD = 1e9 + 7 ;
int size = 10000000;


void solve() {

  int n; cin >> n;
  string s; cin >> s;

  vi r, b, g;
  for ( int i = 0; i < n ; i++ ) {
    if ( s[i] == 'R') r.pb(i);
    else if ( s[i] == 'G') g.pb(i);
    else b.pb(i);
  }
  int ans = 0 ;

  //debug(r, g, b);
  for ( int i = 0; i < (int)r.size() ; i ++ ) {
    for ( int j = 0 ; j < (int)g.size() ; j++) {

      int mn = min({r[i], g[j]});
      int mx = max({r[i], g[j]});

      int v1 = 2 * mn - mx;
      int v2 = 2 * mx - mn;
      double v3 = (double)(mx + mn) / 2;

      if ((int)b.size() > 0) {

        int id = lower_bound(b.begin(), b.end(), v1) - b.begin();
        if (id < n &&  b[id] == v1) ans--;

        id = lower_bound(b.begin(), b.end(), v2) - b.begin();
        if (id < n && b[id] == v2) ans--;

        if (v3 == floor(v3)) {
          id = lower_bound(b.begin(), b.end(), v3) - b.begin();
          if (id < n  && b[id] == v3) ans--;
        }
        ans += (int)b.size();

      }

    }
  }

  cout << ans << endl;

}


int32_t main() {
  fast;
  /*  #ifndef ONLINE_JUDGE
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif */

  int T = 1; //cin>>T;
  while (T--) {
    solve();
  }

  return 0;
}

