#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main(){
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<ll>p(a), q(b), res, r;
    rep(i, 0, a)cin >> p[i];
    rep(i, 0, b)cin >> q[i];
    rep(i, 0, c){
        ll r2;
        cin >> r2;
        r.push_back(r2);
    }
    sort(p.begin(),p.end(),greater<ll>());
    sort(q.begin(),q.end(),greater<ll>());
    sort(r.begin(),r.end(),greater<ll>());
    ll ans = 0;
    rep(i, 0, x)res.push_back(p[i]);
    rep(i, 0, y)res.push_back(q[i]);
    rep(i, 0, c)res.push_back(r[i]);
    sort(res.begin(),res.end(),greater<ll>());
    rep(i, 0, x+y)ans += res[i];
    cout << ans << endl;
}