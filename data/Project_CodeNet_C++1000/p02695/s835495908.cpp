#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);

ll n, m, q, ans;
vector<ll> a, b, c, d;

void dfs(vector<ll> v){
    if(v.size() == n+1){
        ll now = 0;
        rep(i,q){
            if(v[b[i]]-v[a[i]] == c[i]) now += d[i];
        }
        ans = max(ans, now);
        return;
    }
    v.push_back(v.back());
    while(v.back() <= m){
        dfs(v);
        v.back()++;
    }
}

int main(void)
{
    cin >> n >> m >> q;
    a = b = c = d = vector<ll>(q);
    rep(i,q) cin >> a[i] >> b[i] >> c[i] >> d[i];
    dfs(vector<ll>(1,1));
    cout << ans << endl;
    return 0;
}