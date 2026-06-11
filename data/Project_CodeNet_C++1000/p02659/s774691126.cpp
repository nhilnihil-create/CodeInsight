#include <bits/stdc++.h>
using namespace std;
#define f(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define pb push_back
#define fr first
#define sc second
#define len(s) s.size()
#define all(v) v.begin(), v.end()
#define tr(it, v) for (auto &it : v)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef map<int, int> mii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<vi> vvi;
// =================

const int mod = 1e9;
const int N = 3e5 + 1;

void solve()
{
    ll a,b; cin>>a>>b;
    char c; cin>>c;
    int d; cin>>d;
    b*=100;
    b+=d;
    ll ans=a*b;
    cout<<ans/100;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    while (t--)
        solve();
    return 0;
}