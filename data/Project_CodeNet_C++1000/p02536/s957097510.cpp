#include <bits/stdc++.h>
#include<atcoder/all>

#define ll long long
#define ld long double

#define rep(i, n) for(ll i = 0; i < n; ++i)
#define rep2(i, a, b) for(ll i = a; i <= b; ++i)
#define rrep(i, a, b) for(ll i = a; i >= b; --i)

#define pii pair<int, int>
#define pll pair<ll, ll>

#define fi first
#define se second

#define pb push_back
#define eb emplace_back

#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>

#define all(a) a.begin(), a.end()

#define endl '\n'
using namespace std;
using namespace atcoder;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const ll MOD=10000007;//998244353
const ll INF=1e18;
const int inf=1e9;
const double PI=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
 
const int MAX=1e6+10;



int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  int n,m;
  cin >> n >> m;
  dsu tree(n);
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    tree.merge(a,b);
  }
  int ans = tree.groups().size()-1;
  
  cout << ans << endl;
  
  return 0;
}
