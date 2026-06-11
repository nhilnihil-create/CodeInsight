#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef pair<ll,ll> pii;
typedef pair<ll,ll> pll;
typedef map<ll,ll> mii;
typedef map<ll,ll> mll;
typedef vector<pii> vii;
typedef vector<pll> vll;
#define fi first
#define se second
#define pi 3.141592653589793
#define ld long double
#define mod 998244353ll
#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.begin(), v.end(), greater<ll>()
#define tc ll t;cin>>t;while(t--)
#define pqmax priority_queue<ll>
#define pqmin priority_queue<ll,vi,greater<ll>>
#define fio ios_base::sync_with_stdio(0), cin.tie(NULL)
#define tc_g ll tt;cin>>tt;for(ll ti=1;ti<=tt;ti++)#define case_g "Case #"<<ti<<": "
#define Debug(x) cout << x << "\n"
using namespace std;
vl graph[100005];
vector<bool> visited(100005);
void dfs(ll root) {
    for(auto x: graph[root]) {
        if(!visited[x]) {
            visited[x] = true;
            dfs(x);
        }
    }
    return;
}
int main() {
    ll n, m, from, to;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        cin >> from >> to;
        graph[from].pb(to);
        graph[to].pb(from);
    }
    ll ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(i);
            ++ans;
        }
    }
    cout << ans - 1;
}
