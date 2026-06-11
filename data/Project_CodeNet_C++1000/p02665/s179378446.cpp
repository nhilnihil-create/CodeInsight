#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=510000;
const double pi=acos(-1);
int dx[8] = {1,0,-1,0,1,1,-1,-1};
int dy[8] = {0,1,0,-1,-1,1,1,-1};
int d[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  int n;
  cin >> n;
  vector<ll>a(n+1);
  rep(i,n+1) cin >> a[i];
  vector<ll>ans(n+1);
  vector<P>m(n+1);
  
  for(int i = n; i >= 0; i--){
    if(i==n)m[i]=P(a[i],a[i]);
    else{
      ll mi = a[i] + (m[i+1].first+1)/2;
      ll ma = a[i] + m[i+1].second;
      m[i] = P(mi,ma);
    }
  }
  if(1 < m[0].first  || m[0].second < 1 ){
    cout << -1 << endl;
    return 0;
  }
  rep(i,n+1){
    if(i == 0)ans[0] = 1;
    else{
      ans[i] = min(2*(ans[i-1]-a[i-1]),m[i].second);
    }
  }
  ll res = 0;
  rep(i,n+1) res += ans[i];
  cout << res << endl;
  return 0;
}
