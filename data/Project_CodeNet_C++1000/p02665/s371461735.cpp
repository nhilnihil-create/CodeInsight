#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < n; i++)
#define Rep(i,n) for(int i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main(){
    int n;
    cin >> n;
    n++;
    V<int> a(n);
    rep(i,n) cin >> a[i];
    // pair = (min, max);
    V<Pl> cnt(n);
    cnt[n-1] = make_pair(a[n-1], a[n-1]);
    for(int i = n-2; i >= 0; i--) {
        cnt[i].fi = (cnt[i+1].fi+1)/2 + a[i];
        cnt[i].se = cnt[i+1].se + a[i];
    }
    if(!(cnt[0].fi <= 1 && 1 <= cnt[0].se)) {
        cout << -1 << endl;
        return 0;
    }
    // rep(i,n) cout << cnt[i].fi << " " << cnt[i].se << endl;
    V<ll> ans(n);
    ans[0] = 1;
    Rep(i,n-1) {
        ans[i] = min(cnt[i].se, (ans[i-1]-a[i-1])*2);
    }
    ll sum = 0;
    rep(i,n) {
        // cout << ans[i] << endl;
        sum += ans[i];
    }
    cout << sum << endl;
}
