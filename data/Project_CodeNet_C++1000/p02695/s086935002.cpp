#include <bits/stdc++.h>
#include <vector> 
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

#define int long long
using namespace std;
const int MX = 1e6;
const int inf = 1e9;
const int mod = 1e9+7;
using ll = long long;
using P = pair<ll, ll>;
vector<int> to[100005];
int cost[100005];

int x[10];
int y[10];

double dist(ll i, ll j) {
    int xx = (x[i]-x[j])*(x[i]-x[j]);
    int yy = (y[i]-y[j])*(y[i]-y[j]);
    return sqrt(xx+yy);
}

int a[51],b[51],c[51],d[51];
int A[11];
int n, m, q;
ll ans = 0;
void dfs(int dep) {
    //cout << dep << endl;
    if (dep == n+1) {
        int tmp = 0;
        rep(i,q) {
            if(A[b[i]]-A[a[i]]==c[i]) {
                tmp += d[i];
            }
        }
        ans = max(tmp, ans);
        return;
    }
    FOR(i, min(m,A[dep]),m+1) {
        A[dep+1] = i;
        dfs(dep+1);
    }
}

signed main(){
    cin >> n >> m >> q;
    //cout << n <<m << q<< endl;
    rep(i,q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    A[0] = 1;
    dfs(0);
    cout << ans << endl;

    return 0;
}

