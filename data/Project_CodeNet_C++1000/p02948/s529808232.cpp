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

int main() {
    int N,M;cin>>N>>M;
    vector<priority_queue<int>> tbl(100010);
    rep(i,N) {
        int a,b;cin>>a>>b;
        tbl[a].push(b);
    }
    ll ans = 0;
    priority_queue<P> pq;
    for(int i = 1;i<M+1;i++) {
        if(tbl[i].size()!=0) {
            int val = tbl[i].top();
            tbl[i].pop();
            pq.push(P(val,i));
        }
        if(!pq.empty()) {
            int val = pq.top().first;
            int day = pq.top().second;
            pq.pop();
            ans += val;
            if(tbl[day].size()!=0) {
                int val = tbl[day].top();
                tbl[day].pop();
                pq.push(P(val,day));
            }
        }
    }
    cout<<ans<<endl;
}