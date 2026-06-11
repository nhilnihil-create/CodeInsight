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

int nxt[65][200010];

int main() {
    ll n,k;cin>>n>>k;
    rep(i,n) {
        cin>>nxt[0][i];
        nxt[0][i]--;
    }
    rep(i,60) {
        rep(j,n) {
            nxt[i+1][j]=nxt[i][nxt[i][j]];
        }
    }
    int goal = 0;
    rep(i,60) {
        if(k&(1LL<<i)) goal = nxt[i][goal];
    }
    cout<<goal+1<<endl;
}