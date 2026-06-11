#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define mii make_pair<int, int>
#define mll make_pair<ll, ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define all(v) (v).begin(), (v).end()

ofstream out("debug.txt");

const int MxN = 1e5, md = 1e9 + 7;

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vb p(1e6 + 1, 1);
    for (ll i = 2; i * i <= 1e6; ++i)
        if (p[i])
            for (ll j = i * i; j <= 1e6; j += i)
                p[j] = 0;
    vl prime;
    for (ll i = 2; i <= 1e6; ++i)
        if (p[i])
            prime.push_back(i);

    int n;
    cin >> n;
    vl v(n), tb(1e6 + 1, 0);
    ll g;
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        tb[v[i]]++;
        if (i)
            g = gcd(g, v[i]);
        else
            g = v[i];
    }
    int mul;
    bool pw = 1;
    for (auto a : prime)
    {
        mul = 0;
        for (int i = a; i <= 1e6; i += a)
            mul += tb[i];
        if (mul >= 2)
        {
            pw = 0;
            break;
        }
    }
    if (g > 1)
        cout << "not coprime";
    else if (pw)
        cout << "pairwise coprime";
    else
        cout << "setwise coprime";
}