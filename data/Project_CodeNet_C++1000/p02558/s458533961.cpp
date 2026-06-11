#include <atcoder/all>
#define INF 1e9
using namespace std;
using namespace atcoder;
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a)  (a).begin(),(a).end()
#define endl "\n"

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
typedef long long ll;

void solve() {
    int n,q,t,u,v;
    cin>>n>>q;
    dsu d(n);
    while (q--) {
        cin>>t>>u>>v;
        if(t == 0) d.merge(u,v);
        else cout<<d.same(u,v)<<endl;
    }
}

int main() {
    solve();
    return 0;
}