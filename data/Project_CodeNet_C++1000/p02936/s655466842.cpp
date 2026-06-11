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

vector<int> ki[200010];

ll sum[200010];
bool seen[200010];

int main() {
    int n,m;cin>>n>>m;
    rep(i,n-1) {
        int a,b;cin>>a>>b;
        a--;b--;
        ki[a].push_back(b);
        ki[b].push_back(a);
    }
    rep(i,m) {
        int p,x;cin>>p>>x;
        p--;
        sum[p]+=x;
    }
    queue<int> qu;
    qu.push(0);
    seen[0]=true;
    while(!qu.empty()) {
        int now = qu.front();qu.pop();
        for(auto nxt: ki[now]) {
            if(!seen[nxt]) {
                seen[nxt]=true;
                sum[nxt]+=sum[now];
                qu.push(nxt);
            }
        }
    }
    rep(i,n) {
        cout<<sum[i]<<" ";
        if(i==n-1) cout<<endl;
    }
}