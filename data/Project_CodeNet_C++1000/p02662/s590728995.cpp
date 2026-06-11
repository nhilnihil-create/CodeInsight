#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvll vector<vll>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define pii pair<int, int>
#define vpli vector<pair<long long, int>>
#define deb(x) cout << "deb " << #x << " " << x << endl;
#define all(x) x.begin(), x.end()
#define endl "\n"
const ll BIG = 1e18;
const int MOD =  998244353;

void swap(ll &a, ll &b)
{
    ll t = a;
    a = b;
    b = t;
}

ll Min(ll a, ll b, ll c)
{
    return min(a, min(b, c));
}

void printvec(vi &vec)
{
    for (int x : vec)
    {
        cout << x << " ";
    }
    cout << endl;
}

int sum(int a)
{
    int ans = 0;
    while (a)
    {
        ans += (a % 10);
        a = a / 10;
    }
    return ans;
}
void print(vi &mp)
{
    for (auto x : mp)
    {
        cout << x;
    }
    cout << endl;
}
/*
void mulmod(ll &a,ll b )
{
    a += MOD;
    b += MOD;
    return (a*b)%MOD;
}
*/
void solve()
{
    int n, s;
    cin >> n >> s;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vvll dp(n + 1, vll(s + 1));
    ll mul = 1;
    for (int i = 0; i <= s; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = mul;
        mul = (mul*2)%MOD;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j = 1;j<=s;j++)
        {
            dp[i][j] = (2*dp[i-1][j])%MOD;
            if(j-a[i]>=0)
            {
                dp[i][j] = (dp[i][j] +  dp[i-1][j-a[i]])%MOD;
                if(dp[i][j]<0) dp[i][j] += MOD;
            }
        }
    }
    cout<<dp[n][s];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}