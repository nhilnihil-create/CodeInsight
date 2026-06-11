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
    int N;cin>>N;
    vector<ll> p(N),pos(N+1);
    rep(i,N) {
        cin>>p[i];
        pos[p[i]] = i+1;
    }

    ll ans = 0;
    multiset<ll> ms;
    ms.insert(0);
    ms.insert(0);
    ms.insert(N+1);
    ms.insert(N+1);

    for(int i = N;i>=1;i--) {
        auto it = ms.lower_bound(pos[i]);
        ll r1 = *it;
        it++;
        ll r2 = *it;
        it--;
        it--;
        ll l1 = *it;
        it--;
        ll l2 = *it;
        ans += (l1-l2)*(r1-pos[i])*i;
        ans += (pos[i]-l1)*(r2-r1)*i;
        ms.insert(pos[i]);
    }
    cout<<ans<<endl;
}