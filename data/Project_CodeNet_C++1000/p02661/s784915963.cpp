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

int n;
vector<int> frt;
vector<int> bk;
void solve()
{
    cin>>n;
    frt.resize(n);
    bk.resize(n);
    forn(i, n) cin>>frt[i] >> bk[i];
    sort(frt.begin(), frt.end());
    sort(bk.rbegin(), bk.rend());

    if (n%2)
    {
        cout << bk[n/2] - frt[n/2] + 1;
    }
    else
    {
        cout << bk[n/2] - frt[n/2] + bk[(n-1)/2] - frt[(n-1)/2] + 1 << '\n';
    }
    cout << '\n';
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