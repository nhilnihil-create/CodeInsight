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

ll a[300010];
ll cumsum[65][300010],cnt[65];

int main() {
    int n;cin>>n;
    rep(i,n) cin>>a[i];
    rep(i,64) {
        rep(j,n) {
            if((a[j]>>i)&1) cumsum[i][j+1]=cumsum[i][j]+1;
            else cumsum[i][j+1] = cumsum[i][j];
        }
    }
    rep(i,n-1) {
        rep(j,64) {
            if((a[i]>>j)&1) {
                ll num = (n-cumsum[j][n]-(i+1)+cumsum[j][i+1]);
                cnt[j] += num;
            } else {
                cnt[j] += (cumsum[j][n]-cumsum[j][i+1]);
            }
            cnt[j]%=MOD;
        }
    }
    ll ans = 0;
    // rep(i,64) {
    //     rep(j,cnt[i]) {
    //         ans = (ans + (1LL<<i)) % MOD;
    //     }
    // }
    ll two = 1;
    rep(i,64) {
        ans = (ans + (cnt[i]*two)%MOD) %MOD;
        two=(two*2) %MOD;
    }
    cout<<ans%MOD<<endl;
}