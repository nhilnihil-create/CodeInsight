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
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define pb push_back

void solve()
{
    int n, m; cin>>n>>m;
    int c = 0;
    int lf = 0, rg = n-1;
    int f = 0;
    while(c<m)
    {
        int delta = rg - lf;
        if (delta<=n/2 &&n%2==0 &&f==0)
        {
            f=1;
            --rg;
            continue;
        }
        cout << lf + 1 << ' ' << rg  + 1 << '\n';
        ++c;
        ++lf, --rg;
    }

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
