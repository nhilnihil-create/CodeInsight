#include<bits/stdc++.h>
using namespace std;
#define ar array
#define endl '\n'
#define ll long long
#define in insert
#define pb push_back
#define vt vector
#define P_Q(x) priority_queue<x>
#define p_q(x) priority_queue<x, vector<x>, greater<x>>
#define Rep(i,a,b) for(ll i=a;i<=b;i++)
#define Rev(i,a,b) for(ll i=a;i>=b;i--)
#define FOR(m) Rep(i,1,m)
#define For(m) Rep(i,0,m-1)
#define Rbl(x,a) for(auto &x : a)
#define FIO ios::sync_with_stdio(0);   cin.tie(0);
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define vpii vector<pii>
#define vpll vector<pll>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int) (x).size()
// const ll INF = 0x3f3f3f3f3f3f3f3fll;
const ll INF = 1e18L + 5;
#define mod 1000000007
 
const int mxN = 5e3 + 1;
ll p[mxN];
ll c[mxN];
ll n, M;
 
 
int main()
{
FIO
 
    cin >> n >> M;
    FOR(n) cin >> p[i];
    FOR(n) cin >> c[i];
    ll ans = -INF;
    Rep(i,1,n)
    {
        ll j = p[i];
        vt<ll> vec;
        ll moves = M;
        vt<bool> vis(n+1, 0);
        while(!vis[j])
        {
            vis[j] = 1;
            j = p[j];
        }
        ll k = p[i];
        ll cur = 0;
        // cout << j << endl;
        while(k != j && moves)
        {
            cur += c[k];
            ans = max(ans, cur);
            // cout << cur << endl;
            moves--;
        }
        ll stable = cur;
        if(!moves) continue;
        vec.pb(c[j]);
        k = p[j];
        while(k != j)
        {
            vec.pb(vec.back() + c[k]);
            k = p[k];
        }
        ll temp = moves / sz(vec);
        cur += temp * vec.back();
        ll id = moves % sz(vec);
        // ans = max(ans, cur);
        if(id) 
            ans = max(ans, cur + *max_element(vec.begin(), vec.begin() + id));
        if(moves /sz(vec))
        {
            ll maxi = *max_element(all(vec));
            ans = max(ans, max(stable, cur - vec.back()) + maxi);
        }
        else
            ans = max(ans, stable + *max_element(vec.begin(), vec.begin() + id));
    }
    cout << ans << endl;
}