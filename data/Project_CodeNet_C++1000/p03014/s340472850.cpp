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

struct Info {
    int l,r,u,d;
};

int main() {
    int H,W;cin>>H>>W;
    vector<string> field(H);
    rep(i,H) cin>>field[i];
    vector<vector<int>> h(H,vector<int>()),w(W,vector<int>());
    rep(i,H) h[i].push_back(-1);
    rep(i,W) w[i].push_back(-1);
    rep(i,H) {
        rep(j,W) {
            if(field[i][j]=='#') {
                h[i].push_back(j);
                w[j].push_back(i);
            }
        }
    }
    rep(i,H) h[i].push_back(W);
    rep(i,W) w[i].push_back(H);

    vector<vector<Info>> info(H,vector<Info>(W));
    rep(i,H) {
        int l = h[i][0],r=h[i][1],nxt=2;
        rep(j,W) {
            if(j==r) {
                l = r;
                r = h[i][nxt];
                nxt++;
            }
            info[i][j].l = l;
            info[i][j].r = r;
        }
    }
    rep(i,W) {
        int u = w[i][0],d = w[i][1], nxt = 2;
        rep(j,H) {
            if(j==d) {
                u = d;
                d = w[i][nxt];
                nxt++;
            }
            info[j][i].u = u;
            info[j][i].d = d;
         }
    }
    int ans = 0;
    rep(i,H) {
        rep(j,W) {
            if(field[i][j]=='#') continue;
            // P hinf = info[i][j].first,winf = info[i][j].second;
            ans = max(ans,info[i][j].r-info[i][j].l-1+info[i][j].d-info[i][j].u-1-1);
        }
    }
    cout<<ans<<endl;  
}