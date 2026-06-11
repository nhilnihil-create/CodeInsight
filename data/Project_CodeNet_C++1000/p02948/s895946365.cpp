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

vector<int> part[100010];

int main() {
    int n,m;cin>>n>>m;
    rep(i,n) {
        int a,b;cin>>a>>b;
        part[a].push_back(b); 
    }
    rep(i,m+1) sort(part[i].begin(),part[i].end());
    int ma=0;
    priority_queue<P> qu;
    ll ans = 0;
    for (int i = 1;i<=m;i++) {
        int sz = part[i].size();
        if(sz) {
            qu.push(P(part[i][sz-1],i));
            part[i].erase(part[i].end()-1);
        }
        if(qu.size()) {
            int sara = qu.top().first,day = qu.top().second;
            qu.pop();
            ans += sara;
            int pre_sz = part[day].size();
            if(pre_sz) {
                qu.push(P(part[day][pre_sz-1],day));
                part[day].erase(part[day].end()-1);
            }
        }
    }
    cout<<ans<<endl;
}