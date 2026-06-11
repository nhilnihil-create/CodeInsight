#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
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

#define SEG_LEN (1 << 18)

int seg[SEG_LEN * 2];

// one point
long long int get(int ind){
    ind += SEG_LEN;
    long long int sum = 0;
    sum += seg[ind];
    while(true){
        ind /= 2;
        if(ind == 0)break;
        sum += seg[ind];
    }
    return sum;
}

// range
void add(int l, int r, int x){
    l += SEG_LEN;
    r += SEG_LEN;
    while(l < r){
        if(l % 2 == 1){
            seg[l] += x;
            l++;
        }
        l /= 2;
        if(r % 2 == 1){
            seg[r-1] += x;
            r--;
        }
        r /= 2;
    }
}

int main() {
  ll n,d,a;cin>>n>>d>>a;
  vector<P> xh(n);
  rep(i,n) cin>>xh[i].first>>xh[i].second;
  ll ans = 0;
  sort(xh.begin(),xh.end());
  rep(i,n) {
    ll num = get(i);
    ll gap = xh[i].second - num * a;
    if(gap <= 0) continue;
    ll need = (gap-1)/a + 1;
    ans += need;
    ll plc = upper_bound(xh.begin(),xh.end(),P(xh[i].first + 2 * d,1000000001)) - xh.begin();
    add(i,plc,need);
  }
  cout<<ans<<endl;
}
