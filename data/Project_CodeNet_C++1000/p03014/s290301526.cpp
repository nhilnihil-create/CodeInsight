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

    vllll down(h, vll(w)), left(h, vll(w)), up(h, vll(w)), right(h, vll(w));
    rep(i, 0, h)
    {
        rep(j, 0, w)
        {
            if (i != 0)
                down[i][j] = (s[i - 1][j] == '.') ? down[i - 1][j] + 1 : 0;
            if (j != 0)
                left[i][j] = (s[i][j - 1] == '.') ? left[i][j - 1] + 1 : 0;
        }
    }
    repm(i, h - 1, 0)
    {
        repm(j, w - 1, 0)
        {
            if (i != h - 1)
                up[i][j] = (s[i + 1][j] == '.') ? up[i + 1][j] + 1 : 0;
            if (j != w - 1)
                right[i][j] = (s[i][j + 1] == '.') ? right[i][j + 1] + 1 : 0;
        }
    }
    ll ans = 0;
    rep(i, 0, h)
    {
        rep(j, 0, w)
        {
            if (s[i][j] == '#')
                continue;
            ll sum = left[i][j] + right[i][j] + up[i][j] + down[i][j] + 1;
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}