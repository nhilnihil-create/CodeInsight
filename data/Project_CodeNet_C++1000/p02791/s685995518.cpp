#include <bits/stdc++.h>
using namespace std;
 
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
 
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;
 
const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;
 
const int MAX = 1000000;
const int MOD = 1000000007;
 
ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }
 
int main(){
  int n;
  cin >> n;
  vector<int>p(n),p2(n);
  rep(i, 0, n)cin >> p[i];
  int mx = 200200, cnt=0;
  rep(i, 0, n){
    chmin(mx,p[i]);
    p2[i] = mx; 
  }
  rep(i,0,n){
    if(i==0){
      cnt++;
      continue;
    }else{
      if(p2[i-1]>=p[i]){
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}