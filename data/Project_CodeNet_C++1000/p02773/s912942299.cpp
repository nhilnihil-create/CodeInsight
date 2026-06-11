#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i = 0; i < n; i++)
#define Rep(i,n) for(ll i = 0; i <= n; i++)
#define REp(i,n) for(ll i = 1; i < n; i++)
#define REP(i,n) for(ll i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main(){
  int n;
  cin >> n;
  map<string, int> mp;
  rep(i,n) {
    string s;
    cin >> s;
    mp[s]++;
  }
  int mx = 0;
  for(auto x : mp) {
    chmax(mx, x.se);
  }
  V<string> v;
  for(auto x : mp) {
    if(x.se == mx) v.push_back(x.fi);
  }
  sort(all(v));
  rep(i,sz(v)) cout << v[i] << endl;
} 