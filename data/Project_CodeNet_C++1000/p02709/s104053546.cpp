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

int dp[2002][2002];
void solve()
{
    forn(i, 2002) forn(j, 2002) dp[i][j] = LLONG_MIN;
    int n; cin>>n;
    vector<int> a(n);
    forn(i, n) cin>>a[i];
    vector<pair<int,int>> v;
    forn(i, n) v.pb(mp(a[i], i));
    sort(v.rbegin(), v.rend());
    dp[0][0] = 0;
    forn(i, n) for(int j=0;i+j<n;++j)
    {
        int k = i+j;
        dp[i+1][j] = max(dp[i+1][j], dp[i][j] + v[k].f * abs(v[k].s - i));
        dp[i][j+1] = max(dp[i][j+1], dp[i][j] + v[k].f * abs(v[k].s - (n-1-j) ));
    }
    int ans = 0;
    for(int i=0;i<=n;++i) ans = max(ans, dp[i][n-i]);
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
