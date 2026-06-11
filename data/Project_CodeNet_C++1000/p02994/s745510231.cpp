#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);++i)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};

const int MAX=510000;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  int n,l;
  cin >> n >> l;
  int sum = 0;
  rep(i,n){
    sum+=l+i;
  }
  int ans = 0;
  int g=MAX;
  rep(i,n){
    int res = 0;
    rep(j,n){
      if(i==j)continue;
      res+=l+j;
    }
    if(abs(sum-res)<g){
      g=abs(sum-res);
      ans=res;
    }
  }
  cout << ans << endl;
  return 0;
}