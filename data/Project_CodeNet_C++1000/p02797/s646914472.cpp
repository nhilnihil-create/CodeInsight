#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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
#define vpi vector<pii>
#define vpll vector<pll>
#define all(a) a.begin(), a.end()

#define endl '\n'
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
  
const int MOD=1e9+7;
const ll INF=1e18;
const double PI=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
 
const int MAX=510000;
const int x = 1e9;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
   
  int n,k,s;
  cin >> n >> k >> s;
  if(s<1e9){
    rep(i,k) cout << s << " ";
    rep(i,n-k) cout << x << " ";
  }
  else{
    rep(i,k) cout << x << " ";
    rep(i,n-k) cout << 1 << " ";
  }
  return 0;
}
