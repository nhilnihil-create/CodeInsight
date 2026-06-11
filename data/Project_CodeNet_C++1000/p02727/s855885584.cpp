#include <bits/stdc++.h>
using namespace std;
#pragma region
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << (#x) << "] = [", _print(x)
#else
#define debug(x...)
#endif
#pragma endregion
typedef long long ll;
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define sz(v) int((v).size())
#define int ll
#pragma region
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#pragma endregion


int x, y;
int a, b, c;
vector<int> p, q, r;
void solve()
{
    cin>>x>>y>>a>>b>>c;
    p.resize(a);
    q.resize(b);
    r.resize(c);
    forn(i, a) cin>>p[i];
    forn(i, b) cin>>q[i];
    forn(i, c) cin>>r[i];
    sort(p.rbegin(), p.rend());
    sort(q.rbegin(), q.rend());
    sort(r.rbegin(), r.rend());

    vector<int> f;
    f.reserve(a+b+1);
    forn(i, x) f.pb(p[i]);
    forn(i, y) f.pb(q[i]);
    //
    forn(i, a - 1) p[i+1] += p[i];
    forn(i, b - 1) q[i+1] += q[i];
    forn(i, c - 1) r[i+1] += r[i];
    //
    sort(f.begin(), f.end());

    forn(i, sz(f) - 1) f[i+1] += f[i];
    //
    int ans =  p[x-1] + q[y-1];
    forn(i, c)
    {
        if (sz(f) <= i) break;
        int dlt = f[i];
        int ad = r[i];
        ans = max(ans , p[x-1] + q[y-1] - dlt + ad);
    }
    cout << ans << '\n';
}


signed main()
{
    int T = 1;
    ios_base::sync_with_stdio(0); cin.tie(0);
    //cin >> T;
    for(int i=1;i<=T;++i)
    {
        //cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
