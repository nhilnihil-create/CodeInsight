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

int n;
int iv[100'001], p[100'001];
void solve()
{
    cin>>n;
    for (int i = 1;i <= n;++i) cin>>p[i];
    for (int i = 1; i<=n;++i) iv[p[i]] = i;
    set<int> idx;
    int ans = 0;
    for (int x = n; x >= 1; --x)
    {
        idx.insert(iv[x]);
        vector<int> lps(2, 0), rps(2, n+1);
        auto it = idx.find(iv[x]);
        for (int j = 0; j < 2 && it!= idx.begin(); ++j)
        {
            --it;
            lps[j] = *it;
        }
        it = ++idx.find(iv[x]);
        for (int j = 0; j < 2 && it != idx.end(); ++j)
        {
            rps[j] = *it;
            ++it;
        }
        ans += x*((rps[1]-rps[0])*(iv[x]-lps[0])+(rps[0]-iv[x])*(lps[0]-lps[1]));
    }
    cout << ans << '\n';
}

signed main()
{
    int T = 1;
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(22);
    // cin >> T;
    for(int i=1;i<=T;++i)
    {
        //cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
