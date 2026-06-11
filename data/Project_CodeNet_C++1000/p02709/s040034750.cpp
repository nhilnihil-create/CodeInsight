// WeirdBugsButOkay

# include <bits/stdc++.h>

# define ll long long
# define ld long double
# define pii pair <int,int>
# define pll pair <ll,ll>
# define mp make_pair
# define pb push_back
# define ff first
# define ss second
# define endl '\n'

using namespace std;

ll pow3(ll a, ll b, ll m = 1000000007)
{
    ll res = 1;
    while(b > 0)
    {
        if(b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

void solve()
{
    ll n;
    cin >> n;
    pll a[n + 1];
    for(ll i = 1; i <= n; i++)
    {
        cin >> a[i].ff;
        a[i].ss = i;
    }
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    //for(ll i = 1; i <= n; i++)
        //cout << a[i].ff << " " << a[i].ss << endl;
    ll dp[n + 1][n + 1];
    for(ll i = 0; i <= n; i++)
        for(ll j = 0; j <= n; j++)
            dp[i][j] = 0;
    for(ll i = 1; i <= n; i++)
    {
        dp[i][0] = max(dp[i - 1][0] + abs(a[i].ss - i) * a[i].ff, dp[i][0]);
        dp[0][i] = max(dp[0][i - 1] + abs(a[i].ss - (n - i + 1)) * a[i].ff, dp[0][i]);
        for(ll j = 1; j < i; j++)
            dp[i - j][j] = max(dp[i - j - 1][j] + abs(a[i].ss - (i - j)) * a[i].ff, dp[i - j][j - 1] + abs(a[i].ss - (n + 1 - j)) * a[i].ff); 
    }
    //for(ll i = 0; i <= n; i++)
    //{
        //for(ll j = 0; j <= n; j++)
            //cout << dp[i][j] << " ";
        //cout << endl;
    //}
    ll ans = 0;
    for(ll i = 0; i <= n; i++)
        ans = max(ans, dp[i][n - i]);
    cout << ans << endl;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll q = 1;
    //cin >> q;
    for(ll i = 0; i < q; i++)
    {
        solve();
    }
    return 0;
}
