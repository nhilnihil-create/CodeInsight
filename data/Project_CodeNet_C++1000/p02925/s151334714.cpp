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
//#define int ll
#pragma region
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#pragma endregion

int n;
vector<int> g[111'111'1];
int deg[111'111'1];
int dp[111'111'1];
void solve()
{
    cin>>n;
    auto idx = [&](int i, int j)
    {
        if (i > j) swap(i, j);
        return i*n + j;
    };
    forn(i, n)
    {
        int pv = -1;
        forn(j, n-1)
        {
            int p; cin>>p;
            --p;
            if (pv != -1)
            {
                int t1 = idx(i, pv);
                int t2 = idx(i, p);
                g[t1].pb(t2);
                deg[t2]++;
            }
            pv = p;
        }
    }
    queue<int> q;
    forn(i, n*n)
    {
        if (deg[i] == 0) q.push(i);
    }

    while(sz(q))
    {
        int now = q.front(); q.pop();
        for (int nxt: g[now])
        {
            dp[nxt] = max(dp[nxt], dp[now] + 1);
            deg[nxt]--;
            if (deg[nxt] < 0)
            {
                cout << "-1\n";
                return;
            }
            else if(deg[nxt] == 0) q.push(nxt);
        }
    }
    int ans = 0;
    forn(i, n*n)
    {
        if (deg[i])
        {
            cout << "-1\n";
            return;
        }
        ans = max(ans, dp[i]);
    }
    cout << ans+1 << '\n';
}

signed main()
{
    int T = 1;
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(22);
    //cin >> T;
    for(int i=1;i<=T;++i)
    {
        //cout << "Case #" << i << '\n';
        solve();
    }
    return 0;
}