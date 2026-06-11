#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define rep(i, a, n) for (ll i = a; i < n; i++)
#define repm(i, a, n) for (ll i = a; i >= n; i--)
#define INF 1e9
#define LINF 1e17
#define MOD (int)(1e9 + 7)
#define mod (int)(1e9 + 7)
#define pi 3.141592653589
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vd vector<double>
#define vb vector<bool>
#define vs vector<string>
#define vii vector<vector<int>>
#define vllll vector<vector<ll>>
#define ALL(a) (a).begin(), (a).end()

int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

void print(bool f)
{
    cout << (f ? "Yes" : "No") << endl;
}

void Print(bool f)
{
    cout << (f ? "YES" : "NO") << endl;
}

int main(void)
{
    ll h, w;
    cin >> h >> w;
    vs s(h);
    rep(i, 0, h) cin >> s[i];

    vllll dp(h + 1, vll(w + 1, INF));
    dp[0][0] = (s[0][0] == '#');
    rep(i, 0, h)
    {
        rep(j, 0, w)
        {
            if (j != 0)
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + (s[i][j] == '#' && s[i][j - 1] == '.'));
            if (i != 0)
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + (s[i][j] == '#' && s[i - 1][j] == '.'));
        }
    }
    cout << dp[h - 1][w - 1] << endl;
}