#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl;
// *min_element(c + l, c + r) *max_element(c + l, c + r)
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// struct Edge {
//   int to, id;
//   Edge(int to, int id): to(to), id(id) {}
// };

int N;
ll K;
// vector<int> a(N),f(N);
ll a[200010],f[200010];

bool ok(ll mid) {
  ll cnt = 0;
  rep(i,N) {
    if(f[i]*a[i] <= mid) continue;
    cnt += (f[i]*a[i] -mid - 1)/f[i] + 1;
  }
  return (cnt <= K);
}

ll bi_search() {
  ll l = -1,r = 10000000000000,mid;
  while(r-l>1) {
    mid = (r+l)/2;
    // cout<<mid<<endl;    
    if(ok(mid)) r = mid;
    else l = mid;
  }
  return r;
}

int main() {
  cin>>N>>K;
  // a = vector<int>();
  // f = vector<int>();
  rep(i,N) cin>>a[i];
  rep(i,N) cin>>f[i];
  sort(a,a+N);
  sort(f,f+N);
  reverse(f,f+N);
  ll ans = bi_search();
  cout<<ans<<endl;
}
