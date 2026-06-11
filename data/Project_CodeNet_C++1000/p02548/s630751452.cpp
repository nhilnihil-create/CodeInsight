#include <bits/stdc++.h>
#include <math.h>
#include <iostream>
#include <list>
#include <cmath>
#include <queue>
using namespace std;
#define fo(i, n) for (ll i = 0; i < n; ++i)
#define ll long long
void sor(vector<ll> &x)
{
    sort(x.begin(), x.end());
}

void rev(vector<ll> &x)
{
    reverse(x.begin(), x.end());
}

ll gcd(ll x, ll y)
{
    if (y == 0)
    {
        return x;
    }
    return gcd(y, x % y);
}

list<ll> a[5];
void bfs(int src)
{
    queue<int> q;
    bool *vis = new bool[5 + 1]{0};
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int node = q.front();
        cout << node << " ";
        q.pop();
        for (int n : a[node])
        {
            if (!vis[n])
            {
                q.push(n);
                vis[n] = true;
            }
        }
    }
}

ll max(ll x, ll y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}

ll min(ll x, ll y)
{
    if (x > y)
    {
        return y;
    }
    else
    {
        return x;
    }
}

void primeFactors(ll n, vector<ll> &vec)
{

    while (n % 2 == 0)
    {
        vec.push_back(2);
        n = n / 2;
    }

    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            vec.push_back(i);
            n = n / i;
        }
    }

    if (n > 2)
        vec.push_back(n);
}

ll lcm(ll x, ll y)
{
    return x * y / gcd(x, y);
}

ll g(ll x)
{
    for (ll i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return i;
        }
    }
    return 0;
}

ll countDivisors(ll n)
{
    ll cnt = 0;
    for (ll i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                cnt++;

            else
                cnt = cnt + 2;
        }
    }
    return cnt;
}

void solve()
{
    ll n;
    cin >> n;
    ll ans = 0;
    vector<vector<ll>> a;
    for (ll i = 1; i < n; i++)
    {
        for (ll j = 1; j <= n - i; j++)
        {
            if (i * j < n)
            {
                ans++;
            }
            else
            {
                break;
            }
        }
    }
    cout << ans;
}

int main()
{

    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}

//0 3 1 0 5 2 6
//0 0 1 2 3 5 6