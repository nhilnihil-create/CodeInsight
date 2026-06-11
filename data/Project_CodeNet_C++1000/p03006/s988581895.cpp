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
    ll n;
    cin >> n;
    vll x(n), y(n);
    rep(i, 0, n) cin >> x[i] >> y[i];

    map<pll, ll> mp;
    rep(i, 0, n)
    {
        rep(j, 0, n)
        {
            if (i != j)
                mp[make_pair(x[i] - x[j], y[i] - y[j])]++;
        }
    }
    ll m = 0;
    for (auto x : mp)
        m = max(m, x.second);
    cout << n - m << endl;
}