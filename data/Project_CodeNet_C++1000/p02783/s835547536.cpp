#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define DESYNC ios::sync_with_stdio(0); cin.tie(0);
#define deb(x) cerr << ">> " << #x << " : " << x << "\n";
#define print(a) for(auto x : a) cout << x << " "; cout << "\n";

const int inf = 1e18 + 5;

// +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

void solve()
{
    int h, a;
    cin >> h >> a;
    int ans = (h % a == 0) ? h / a : h / a + 1;
    cout << ans << endl;
}

int32_t main()
{
    DESYNC
    int t = 1;
    // cin >> t;
    while(t--)
        solve();
    return 0;
}