#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i <= n; i++)
#define FORR(i, m, n) for(int i = m; i >= n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;

const ll mod = 1e9+7;
ll ans;
ll n,k;
const ll maxin = 1e5+5;
vll g[maxin];

void dfs(int s, int t){
    ll cnt = k-1;
    if(t != -1) cnt--;
    for(auto p:g[s]){
        if (p==t) continue;
        ans *= cnt;
        ans%=mod;
        cnt--;
        dfs(p,s);
    }

}
int main(){
	
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin>>n>>k;
    REP(i,n-1){
        ll u,v; cin >>u>>v;
        u--; v--;
        g[u].push_back(v); g[v].push_back(u);
    }
    ans = k;
    dfs(0,-1);
    cout << ans << endl;
    
    return 0;
}