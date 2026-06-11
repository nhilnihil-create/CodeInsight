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

int n, k;
vector<int> a, f;
bool test(int ub)
{
    int cnt = 0;
    forn(i, n)
    {
        int now = a[i]*f[i];
        if (now < ub) continue;
        int rem = now - ub;

        int ad = rem / f[i];
        while(ad * f[i] < rem) ++ad;

        cnt += ad;
    }
    return cnt <= k;
}
void solve()
{
    cin>>n>>k;
    a.resize(n);
    f.resize(n);
    forn(i, n) cin>>a[i];
    forn(i, n) cin>>f[i];
    sort(a.begin(), a.end());
    sort(f.rbegin(), f.rend());
    //

    int lf = 0, rg =1e13;
    int fd = 1e13;
    while (lf <= rg)
    {
        int mid = (lf + rg) / 2;
        if (test(mid))
        {
            fd = mid;
            rg = mid - 1;
        }
        else lf = mid + 1;
    }
    cout << fd << '\n';
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
