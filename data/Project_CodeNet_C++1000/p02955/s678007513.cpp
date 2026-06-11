#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
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

vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            if (N/i != i) res.push_back(N/i);
        }
    }
    sort(res.begin(), res.end());
    reverse(res.begin(),res.end());
    return res;
}

ll a[550];

int main() {
  ll n,k;cin>>n>>k;
  rep(i,n) cin>>a[i];
  ll sum = 0;
  rep(i,n) sum+=a[i];
  vector<ll> vec = enum_divisors(sum);
  P b[550];
  rep(i,vec.size()) {
    rep(j,n) b[j]=P(a[j]%vec[i],vec[i]-(a[j]%vec[i]));
    ll minus=0;
    sort(b,b+n);
    int id=0;
    while(1) {
      if(minus+b[id].first<=k) {
	minus+=b[id].first;
	id++;
      } else {
	minus=0;
	break;
      }
    }
    bool ok=true;
    for(int id2=id;id2<n;id2++) {
      minus+=b[id2].second;
      if(minus>k) {
	ok=false;
	break;
      }
    }
    if(ok) {
      cout<<vec[i]<<endl;
      return 0;
    } else {
      continue;
    }
  }
}
