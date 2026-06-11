#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<int, int> Pi;
typedef vector<ll> Vec;
typedef vector<int> Vi;
typedef vector<string> Vs;
typedef vector<P> VP;
typedef vector<vector<ll>> VV;
typedef vector<vector<int>> VVi;
typedef vector<vector<vector<ll>>> VVV;
typedef vector<vector<vector<vector<ll>>>> VVVV;

#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
const ll INF=1e18+18;
const ll MAX=100005;
const ll MOD=1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;
#define ALL(v) v.begin(), v.end()
#define rALL(v) v.rbegin(), v.rend()
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a,b)
#define Each(a,b) for(auto &a :b)
#define REPM(i, mp) for (auto i = mp.begin(); i != mp.end(); ++i)
#ifdef LOCAL
#define dbg(x_) cerr << #x_ << ":" << x_ << endl;
#define dbgmap(mp) cerr << #mp << ":"<<endl; for (auto i = mp.begin(); i != mp.end(); ++i) { cerr << i->first <<":"<<i->second << endl;}
#define dbgarr(n,m,arr) rep(i,n){rep(j,m){cerr<<arr[i][j]<<" ";}cerr<<endl;}
#define dbgdp(n,arr) rep(i,n){cerr<<arr[i]<<" ";}cerr<<endl;
#define dbgmint(n,arr) rep(i,n){cerr<<arr[i].x<<" ";}cerr<<endl;
#define dbgarrmint(n,m,arr) rep(i,n){rep(j,m){cerr<<arr[i][j].x<<" ";}cerr<<endl;}
#else
#define dbg(...)
#define dbgmap(...)
#define dbgarr(...)
#define dbgdp(...)
#define dbgmint(...)
#define dbgarrmint(...)
#endif
#define out(a) cout<<a<<endl
#define out2(a,b) cout<<a<<" "<<b<<endl
#define vout(v) rep(i,v.size()){cout<<v[i]<<" ";}cout<<endl
#define Uniq(v) v.erase(unique(v.begin(), v.end()), v.end())
#define fi first
#define se second


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<std::setprecision(10);

    ll n,m;
    cin>>n>>m;

    VP vp;
    rep(i,n){
        ll a,b;
        cin>>a>>b;
        vp.emplace_back(a,b);
    }
    sort(ALL(vp));
    ll cnt = 0;
    priority_queue<ll> q;
    ll ans = 0;
    REP(i,1,m+1){
        while(cnt<n && vp[cnt].fi<=i){
            q.push(vp[cnt].se);
            cnt++;
        }
        if(!q.empty()){
            ans += q.top();
            q.pop();
        }
    }
    out(ans);
    return  0;
}